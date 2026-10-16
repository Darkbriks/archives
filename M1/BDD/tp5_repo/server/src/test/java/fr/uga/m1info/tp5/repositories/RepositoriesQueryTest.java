package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.enums.GenreMusical;
import fr.uga.m1info.tp5.models.ArtistEntity;
import fr.uga.m1info.tp5.models.PlaylistEntity;
import fr.uga.m1info.tp5.models.SongEntity;
import fr.uga.m1info.tp5.models.UserEntity;
import fr.uga.m1info.tp5.utils.TestUtils;
import jakarta.persistence.EntityManager;
import jakarta.transaction.Transactional;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.ApplicationContext;
import org.springframework.data.jpa.repository.JpaRepository;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.time.Duration;
import java.util.List;
import java.util.Set;

import static org.assertj.core.api.Assertions.assertThat;

@SpringBootTest
@Transactional
@AutoConfigureTestDatabase
class RepositoriesQueryTest {
    @Autowired
    private ApplicationContext applicationContext;
    @Autowired
    private EntityManager entityManager;

    @Autowired(required = false)
    private List<? extends JpaRepository<?,?>> repositories = List.of();

    @BeforeEach
    void tearDown() {
        repositories.forEach(JpaRepository::deleteAll);
    }

    @Test
    void artistRepositoryQuery_use() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Class<?> artistRepository = TestUtils.getClassForNameWithAssertion("fr.uga.m1info.tp5.repositories.ArtistRepository");

        ArtistEntity artistEntityClassic = ArtistEntity
                .builder()
                .name("test1")
                .biography("test 1")
                .genreMusical(GenreMusical.CLASSIC)
                .build();

        ArtistEntity artistEntityVariety1 = ArtistEntity
                .builder()
                .name("test 2")
                .biography("test 2")
                .genreMusical(GenreMusical.VARIETY)
                .build();

        ArtistEntity artistEntityVariety2 = ArtistEntity
                .builder()
                .name("test 3")
                .biography("test 3")
                .genreMusical(GenreMusical.VARIETY)
                .build();

        entityManager.persist(artistEntityClassic);
        entityManager.persist(artistEntityVariety1);
        entityManager.persist(artistEntityVariety2);

        Method gender = TestUtils.getDeclaredMethodWithNameContain(artistRepository, "genre");

        assertThat(gender.invoke(applicationContext.getBean(artistRepository), GenreMusical.VARIETY)).isEqualTo(2);
    }

    @Test
    void playlistRepositoryQuery_use() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Class<?> playlistRepository = TestUtils.getClassForNameWithAssertion("fr.uga.m1info.tp5.repositories.PlaylistRepository");

        List.of(UserEntity.builder()
                .name("Nicolas")
                .mail("nico@gmail.com")
                .build(),
                UserEntity.builder()
                .name("P&C Master")
                .mail("p&cmaster@gmail.com")
                .build()).forEach(entityManager::persist);

        ArtistEntity nicolas = ArtistEntity
                .builder()
                .name("Nicolas")
                .build();
        entityManager.persist(nicolas);

        SongEntity leTitreDeNicolas = SongEntity.builder()
                .title("Le titre de Nicolas")
                .artistEntity(nicolas)
                .duration(Duration.ofSeconds(30))
                .build();

        entityManager.persist(leTitreDeNicolas);

        ArtistEntity pcMaster = ArtistEntity
                .builder()
                .name("P&C Master")
                .build();
        entityManager.persist(pcMaster);

        SongEntity patronAndComposant = SongEntity.builder()
                .title("Patron & composant, c'est cool non ?")
                .artistEntity(pcMaster)
                .duration(Duration.ofDays(300))
                .build();
        entityManager.persist(patronAndComposant);

        List.of(PlaylistEntity.builder()
                        .name("playlist1")
                        .description("test 1")
                        .songEntities(Set.of(
                                leTitreDeNicolas

                        ))
                        .build(),
                PlaylistEntity.builder()
                        .name("playlist2")
                        .description("test 1")
                        .songEntities(Set.of(
                                patronAndComposant
                        ))
                        .build()
        ).forEach(entityManager::persist);
        Method song = TestUtils.getDeclaredMethodWithNameContain(playlistRepository, "song");

        assertThat(song.invoke(applicationContext.getBean(playlistRepository), leTitreDeNicolas))
                .isEqualTo(Set.of(PlaylistEntity.builder()
                        .name("playlist1")
                        .description("test 1")
                        .songEntities(Set.of(
                                leTitreDeNicolas

                        ))
                        .build()));
    }

    @Test
    void songRepositoryQuery_use() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Class<?> playlistRepository = TestUtils.getClassForNameWithAssertion("fr.uga.m1info.tp5.repositories.SongRepository");


        ArtistEntity nicolas = ArtistEntity
                .builder()
                .name("Nicolas")
                .build();
        entityManager.persist(nicolas);

        List.of(SongEntity.builder()
                .title("Le titre de Nicolas")
                .artistEntity(nicolas)
                .duration(Duration.ofSeconds(30))
                .build(),
        SongEntity.builder()
                .title("le second titre")
                .artistEntity(nicolas)
                .duration(Duration.ofSeconds(200))
                .build()
        ).forEach(entityManager::persist);

        ArtistEntity pcMaster = ArtistEntity
                .builder()
                .name("P&C Master")
                .build();
        entityManager.persist(pcMaster);

        List.of(SongEntity.builder()
                .title("Patron & composant, c'est cool non ?")
                .artistEntity(pcMaster)
                .duration(Duration.ofSeconds(300))
                .build(),SongEntity.builder()
                .title("Patron & composant, c'est moyen plutôt ? ")
                .artistEntity(pcMaster)
                .duration(Duration.ofSeconds(1000))
                .build()).forEach(entityManager::persist);

        Method song = TestUtils.getDeclaredMethodWithNameContain(playlistRepository, "duration");

        assertThat(song.invoke(applicationContext.getBean(playlistRepository), Duration.ofSeconds(200), Duration.ofSeconds(400)))
                .isEqualTo(Set.of(SongEntity.builder()
                        .title("le second titre")
                        .artistEntity(nicolas)
                        .duration(Duration.ofSeconds(200))
                        .build(),SongEntity.builder()
                        .title("Patron & composant, c'est cool non ?")
                        .artistEntity(pcMaster)
                        .duration(Duration.ofSeconds(300))
                        .build()));
    }

}



