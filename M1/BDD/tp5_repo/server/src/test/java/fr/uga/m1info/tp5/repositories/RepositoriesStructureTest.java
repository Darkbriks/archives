package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.enums.GenreMusical;
import fr.uga.m1info.tp5.models.*;
import fr.uga.m1info.tp5.utils.TestUtils;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.lang.reflect.Method;
import java.time.Duration;
import java.util.List;
import java.util.Set;
import java.util.stream.Stream;

import static org.assertj.core.api.Assertions.assertThat;

class RepositoriesStructureTest {

    private static Stream<Arguments> repositories() {
        return Stream.of(
                Arguments.of("fr.uga.m1info.tp5.repositories.AlbumRepository", AlbumEntity.class, String.class),
                Arguments.of("fr.uga.m1info.tp5.repositories.ArtistRepository", ArtistEntity.class, String.class),
                Arguments.of("fr.uga.m1info.tp5.repositories.PlaylistRepository", PlaylistEntity.class, String.class),
                Arguments.of("fr.uga.m1info.tp5.repositories.SongRepository", SongEntity.class, String.class),
                Arguments.of("fr.uga.m1info.tp5.repositories.UserRepository", UserEntity.class, String.class)
        );
    }

    @ParameterizedTest
    @MethodSource("repositories")
    void verify(String className, Class<?> entityClass, Class<?> idClass) throws ClassNotFoundException {
        Class<?> clazz = TestUtils.getClassForNameWithAssertion(className);
        TestUtils.verifyRepositoryExtendJpaRepositoryWith(clazz, entityClass, idClass);

    }


    private static Stream<Arguments> queries() {
        return Stream.of(
                Arguments.of("fr.uga.m1info.tp5.repositories.UserRepository", "mail", Set.class, 1, List.of(String.class), false),
                Arguments.of("fr.uga.m1info.tp5.repositories.ArtistRepository", "genre", int.class, 1, List.of(GenreMusical.class), false),
                Arguments.of("fr.uga.m1info.tp5.repositories.PlaylistRepository", "song", Set.class, 1, List.of(SongEntity.class), false),
                Arguments.of("fr.uga.m1info.tp5.repositories.SongRepository", "duration", Set.class, 2, List.of(Duration.class, Duration.class), false)
        );
    }


    @ParameterizedTest
    @MethodSource("queries")
    void artistRepositoryQuery_musicalGenderDeclaration(
            String classNameRepository,
            String nameContainingInQuery,
            Class<Integer> returnTypeClass,
            int nbParameter,
            List<Class<?>> classesParameter,
            boolean forceQuery) throws ClassNotFoundException, NoSuchMethodException {
        Class<?> repository = TestUtils.getClassForNameWithAssertion(classNameRepository);
        Method gender = TestUtils.getDeclaredMethodWithNameContain(repository, nameContainingInQuery);

        assertThat(gender.getReturnType()).isEqualTo(returnTypeClass);
        assertThat(gender.getParameterCount()).isEqualTo(nbParameter);
        for (int i = 0; i < gender.getParameterCount(); i++) {
            gender.getParameterTypes()[i] = classesParameter.get(i);
        }
        if (forceQuery) {
            assertThat(gender.getAnnotations())
                    .as("Cette fonction peut être faite en mode interpolation de nom de fonction")
                    .hasSize(1);
        } else {
            assertThat(gender.getAnnotations())
                    .as("Cette fonction peut être faite en mode interpolation de nom de fonction")
                    .isEmpty();

        }
    }

}
