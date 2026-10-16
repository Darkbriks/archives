package fr.uga.m1info.tp5.utils;

import org.assertj.core.api.AbstractCollectionAssert;
import org.assertj.core.api.Assertions;
import org.assertj.core.api.ObjectAssert;
import org.springframework.data.jpa.repository.JpaRepository;

import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.util.Arrays;
import java.util.Collection;
import java.util.stream.Collectors;

import static org.assertj.core.api.Assertions.assertThat;


public class TestUtils {


    public static Class<?> getClassForNameWithAssertion(String className) throws ClassNotFoundException {
        Assertions.assertThatCode(() -> Class.forName(className))
                .as("La classe [%s] est introuvable", className)
                .doesNotThrowAnyException();
        return Class.forName(className);
    }

    public static Method getDeclaredMethodWithNameContain(Class<?> clazz, String name) throws NoSuchMethodException {
        assertionClassHaveDeclaredMethodContainingName(clazz, name.toLowerCase())
                .as("une méthode qui devrait contenir le terme [%s] est introuvable dans la classe [%s]", name,clazz.getSimpleName())
                .hasSize(1);
        return Arrays.stream(clazz.getDeclaredMethods()).filter(method -> method.getName().toLowerCase().contains(name.toLowerCase())).findFirst().orElseThrow(() -> new NoSuchMethodException(name));
    }

    public static Method getMethodWithNameContainInFirstInterface(Class<?> clazz, String name) throws NoSuchMethodException {
        assertionClassHaveMethodContainingName(clazz, name)
                .as("une méthode qui devrait contenir le terme [%s] est introuvable dans la classe [%s]", name,clazz.getSimpleName())
                .isNotEmpty();
        return Arrays.stream(clazz.getInterfaces()[0].getMethods()).filter(method -> method.getName().toLowerCase().contains(name.toLowerCase())).findFirst().orElseThrow(() -> new NoSuchMethodException(name));
    }


    public static AbstractCollectionAssert<?, Collection<? extends Method>, Method, ObjectAssert<Method>> assertionClassHaveDeclaredMethodContainingName(Class<?> clazz, String name) {
        return assertThat(Arrays.stream(clazz.getDeclaredMethods()).filter(method -> method.getName().toLowerCase().contains(name)).collect(Collectors.toSet()));
    }

    public static AbstractCollectionAssert<?, Collection<? extends Method>, Method, ObjectAssert<Method>> assertionClassHaveMethodContainingName(Class<?> clazz, String name) {
        return assertThat(Arrays.stream(clazz.getMethods()).filter(method -> method.getName().toLowerCase().contains(name.toLowerCase())).collect(Collectors.toSet()));
    }


    public static void verifyRepositoryExtendJpaRepositoryWith(Class<?> clazz, Class<?> entityClass, Class<?> idClass) {
        Arrays.stream(clazz.getGenericInterfaces())
                .filter(type -> type instanceof ParameterizedType parameterizedType && parameterizedType.getRawType() == JpaRepository.class)
                .map(type -> ((ParameterizedType) type).getActualTypeArguments())
                .forEach(repoTypes -> {
                    assertThat(repoTypes).hasSize(2);
                    assertThat(repoTypes[0].getTypeName())
                            .as("Le type de l'entité n'est pas correct dans le repository [%s]", clazz.getSimpleName())
                            .isEqualTo(entityClass.getName());
                    assertThat(repoTypes[1].getTypeName())
                            .as("Le type de l'id de l'entité n'est pas correct dans le repository [%s]", clazz.getSimpleName())
                            .isEqualTo(idClass.getName());
                });
    }
}
