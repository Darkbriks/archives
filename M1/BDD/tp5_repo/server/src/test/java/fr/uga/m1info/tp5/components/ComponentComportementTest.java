package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.enums.GenreMusical;
import fr.uga.m1info.tp5.models.*;
import fr.uga.m1info.tp5.utils.TestUtils;
import jakarta.persistence.EntityManager;
import jakarta.transaction.Transactional;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.ApplicationContext;
import org.springframework.data.jpa.repository.JpaRepository;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.Date;
import java.time.Duration;
import java.time.LocalDate;
import java.util.List;
import java.util.stream.Stream;

import static org.assertj.core.api.AssertionsForClassTypes.assertThat;
import static org.assertj.core.api.AssertionsForClassTypes.assertThatCode;

@SpringBootTest
@Transactional
@AutoConfigureTestDatabase
class ComponentComportementTest {

    @Autowired
    private EntityManager entityManager;

    @Autowired
    private ApplicationContext applicationContext;

    @Autowired(required = false)
    private List<? extends JpaRepository<?,?>> allRepository = List.of();

    @BeforeEach
    void tearDown() {
        allRepository.forEach(JpaRepository::deleteAll);
    }

    @Nested
    @SpringBootTest
    class Read {
        public static Stream<Arguments> getArguments() {
            return Stream.of(
                    Arguments.of("fr.uga.m1info.tp5.components.ArtistComponent", List.of(
                                    UserEntity.builder().name("test1").build(),
                                    UserEntity.builder().name("test2").build(),
                                    ArtistEntity.builder().name("test1").biography("bio of test1").genreMusical(GenreMusical.CLASSIC).build(),
                                    ArtistEntity.builder().name("test3").biography("bio of test3").genreMusical(GenreMusical.RANB).build()
                            ),
                            "getArtiste",
                            new Object[]{"test1"},
                            ArtistEntity.builder().name("test1").biography("bio of test1").genreMusical(GenreMusical.CLASSIC).build()
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.AlbumComponent",
                            List.of(
                                    AlbumEntity.builder()
                                            .title("album1")
                                            .build(),
                                    AlbumEntity.builder()
                                            .title("album2")
                                            .build()
                            ),
                            "getAlbum",
                            new Object[]{"album1"},
                            AlbumEntity.builder()
                                    .title("album1")
                                    .build()
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.PlaylistComponent",
                            List.of(
                                    PlaylistEntity.builder()
                                            .name("playlist1")
                                            .build(),
                                    PlaylistEntity.builder()
                                            .name("playlist2")
                                            .build()
                            ),
                            "getPlaylist",
                            new Object[]{"playlist1"},
                            PlaylistEntity.builder()
                                    .name("playlist1")
                                    .build()
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.SongComponent",
                            List.of(
                                    SongEntity
                                            .builder()
                                            .title("song1")
                                            .build(),
                                    SongEntity
                                            .builder()
                                            .title("song2")
                                            .build()

                            ),
                            "getSong",
                            new Object[]{"song2"},
                            SongEntity
                                    .builder()
                                    .title("song2")
                                    .build()
                    ), Arguments.of("fr.uga.m1info.tp5.components.UserComponent",
                            List.of(
                                    UserEntity.builder()
                                            .name("user1").build(),
                                    UserEntity.builder()
                                            .name("user2").build(),
                                    UserEntity.builder()
                                            .name("user3").build()

                            ),
                            "getUser",
                            new Object[]{"user2"},
                            UserEntity.builder()
                                    .name("user2").build())
            );
        }

        @ParameterizedTest
        @MethodSource("getArguments")
        void read(String classNameComponent, List<Object> prePersist, String methodNameContaining, Object[] args, Object result) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
            Class<?> component = TestUtils.getClassForNameWithAssertion(classNameComponent);
            prePersist.forEach(entityManager::persist);
            Method getter = TestUtils.getDeclaredMethodWithNameContain(component, methodNameContaining);
            assertThat(getter.invoke(applicationContext.getBean(component), args))
                    .usingRecursiveComparison()
                    .isEqualTo(result);
        }

    }


    @Nested
    @SpringBootTest
    class Delete {

        public static Stream<Arguments> getArguments() {
            return Stream.of(
                    Arguments.of("fr.uga.m1info.tp5.components.ArtistComponent",
                            "fr.uga.m1info.tp5.repositories.ArtistRepository",
                            List.of(
                                    ArtistEntity
                                            .builder()
                                            .name("test3")
                                            .biography("bio of test3")
                                            .genreMusical(GenreMusical.RANB)
                                            .build()
                            ),
                            new Object[]{"test3"}
                    ),
                    Arguments.of(
                            "fr.uga.m1info.tp5.components.AlbumComponent",
                            "fr.uga.m1info.tp5.repositories.AlbumRepository",
                            List.of(
                                    AlbumEntity.builder()
                                            .title("album1")
                                            .build()
                            ),
                            new Object[]{"album1"}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.PlaylistComponent",
                            "fr.uga.m1info.tp5.repositories.PlaylistRepository",
                            List.of(
                                    PlaylistEntity.builder()
                                            .name("playlist2")
                                            .build()
                            ),
                            new Object[]{"playlist2"}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.SongComponent",
                            "fr.uga.m1info.tp5.repositories.SongRepository",
                            List.of(
                                    SongEntity
                                            .builder()
                                            .title("song2")
                                            .build()

                            ),
                            new Object[]{"song2"}
                    ), Arguments.of("fr.uga.m1info.tp5.components.UserComponent",
                            "fr.uga.m1info.tp5.repositories.UserRepository",
                            List.of(
                                    UserEntity.builder()
                                            .name("user3").build()

                            ),
                            new Object[]{"user3"}
                    )
            );
        }

        @ParameterizedTest
        @MethodSource("getArguments")
        void delete(String classNameComponent, String repositoryClassName, List<Object> prePersist, Object[] args) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
            Class<?> component = TestUtils.getClassForNameWithAssertion(classNameComponent);
            prePersist.forEach(entityManager::persist);
            Method delete = TestUtils.getDeclaredMethodWithNameContain(component, "delete");
            assertThatCode(() -> delete.invoke(applicationContext.getBean(component), args))
                    .doesNotThrowAnyException();
            Class<?> repositoryClass = TestUtils.getClassForNameWithAssertion(repositoryClassName);
            JpaRepository<?,?> repository = (JpaRepository<?,?>) applicationContext.getBean(repositoryClass);
            assertThat(repository.count())
                    .isEqualTo(0L);
        }


    }

    @Nested
    @SpringBootTest
    class Create {
        public static Stream<Arguments> getArguments() {
            return Stream.of(
                    Arguments.of("fr.uga.m1info.tp5.components.ArtistComponent",
                            "fr.uga.m1info.tp5.repositories.ArtistRepository",
                            new Object[]{ArtistEntity
                                    .builder()
                                    .name("test3")
                                    .biography("bio of test3")
                                    .genreMusical(GenreMusical.RANB)
                                    .build()}
                    ),
                    Arguments.of(
                            "fr.uga.m1info.tp5.components.AlbumComponent",
                            "fr.uga.m1info.tp5.repositories.AlbumRepository",
                            new Object[]{AlbumEntity.builder()
                                    .title("album1")
                                    .build()}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.PlaylistComponent",
                            "fr.uga.m1info.tp5.repositories.PlaylistRepository",
                            new Object[]{PlaylistEntity.builder()
                                    .name("playlist2")
                                    .build()}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.SongComponent",
                            "fr.uga.m1info.tp5.repositories.SongRepository",
                            new Object[]{SongEntity
                                    .builder()
                                    .title("song2")
                                    .build()}
                    ), Arguments.of("fr.uga.m1info.tp5.components.UserComponent",
                            "fr.uga.m1info.tp5.repositories.UserRepository",
                            new Object[]{UserEntity.builder()
                                    .name("user3").build()}
                    )
            );
        }

        @ParameterizedTest
        @MethodSource("getArguments")
        void create(String classNameComponent, String repositoryClassName, Object[] args) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
            Class<?> component = TestUtils.getClassForNameWithAssertion(classNameComponent);
            Method create = TestUtils.getDeclaredMethodWithNameContain(component, "create");
            assertThatCode(() -> create.invoke(applicationContext.getBean(component), args))
                    .doesNotThrowAnyException();
            Class<?> repositoryClass = TestUtils.getClassForNameWithAssertion(repositoryClassName);
            JpaRepository<?,?> repository = (JpaRepository<?,?>) applicationContext.getBean(repositoryClass);
            assertThat(repository.count())
                    .isEqualTo(1L);
        }


    }

    @Nested
    @SpringBootTest
    class Update {
        public static Stream<Arguments> getArguments() {
            return Stream.of(
                    Arguments.of("fr.uga.m1info.tp5.components.ArtistComponent",
                            "fr.uga.m1info.tp5.repositories.ArtistRepository",
                            List.of(
                                    ArtistEntity.builder()
                                            .name("test3")
                                            .biography("bio of test3 à changer")
                                            .build()
                            ),
                            new Object[]{ArtistEntity
                                    .builder()
                                    .name("test3")
                                    .biography("bio of test3")
                                    .genreMusical(GenreMusical.RANB)
                                    .build()}
                    ),
                    Arguments.of(
                            "fr.uga.m1info.tp5.components.AlbumComponent",
                            "fr.uga.m1info.tp5.repositories.AlbumRepository",
                            List.of(
                                    AlbumEntity.builder()
                                            .title("album1")
                                            .build()
                            ),
                            new Object[]{
                                    AlbumEntity
                                            .builder()
                                            .title("album1")
                                            .releaseDate(Date.valueOf(LocalDate.of(2024,12,01)))
                                    .build()}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.PlaylistComponent",
                            "fr.uga.m1info.tp5.repositories.PlaylistRepository",
                            List.of(
                                    PlaylistEntity.builder()
                                            .name("playlist2")
                                            .description("à changer")
                                            .build()
                            ),
                            new Object[]{PlaylistEntity.builder()
                                    .name("playlist2")
                                    .description("playlist 2")
                                    .build()}
                    ),
                    Arguments.of("fr.uga.m1info.tp5.components.SongComponent",
                            "fr.uga.m1info.tp5.repositories.SongRepository",
                            List.of(
                                    SongEntity
                                            .builder()
                                            .title("song2")
                                            .duration(Duration.ZERO)
                                            .build()
                            ),
                            new Object[]{SongEntity
                                    .builder()
                                    .title("song2")
                                    .duration(Duration.ofSeconds(10))
                                    .build()}
                    ), Arguments.of("fr.uga.m1info.tp5.components.UserComponent",
                            "fr.uga.m1info.tp5.repositories.UserRepository",
                            List.of(UserEntity.builder()
                                    .name("user3")
                                            .mail("mail@achnager.com")
                                    .build()
                            ),
                            new Object[]{UserEntity.builder()
                                    .name("user3")
                                    .mail("test@test.com")
                                    .build()}
                    )
            );
        }

        @ParameterizedTest
        @MethodSource("getArguments")
        void update(String classNameComponent, String repositoryClassName, List<Object> prePersist, Object[] args) throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException {
            Class<?> component = TestUtils.getClassForNameWithAssertion(classNameComponent);
            prePersist.forEach(entityManager::persist);
            Method update = TestUtils.getDeclaredMethodWithNameContain(component, "update");
            assertThatCode(() -> update.invoke(applicationContext.getBean(component), args))
                    .doesNotThrowAnyException();
            Class<?> repositoryClass = TestUtils.getClassForNameWithAssertion(repositoryClassName);
            JpaRepository<?,?> repository = (JpaRepository<?, ?>) applicationContext.getBean(repositoryClass);
            assertThat(repository.count()).isEqualTo(1);
        }
    }

}
