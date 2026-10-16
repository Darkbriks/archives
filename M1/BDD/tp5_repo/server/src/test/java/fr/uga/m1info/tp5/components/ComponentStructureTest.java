package fr.uga.m1info.tp5.components;


import fr.uga.m1info.tp5.utils.TestUtils;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Arrays;
import java.util.Set;
import java.util.stream.Collectors;

import static org.assertj.core.api.Assertions.assertThat;

class ComponentStructureTest {


    @ParameterizedTest
    @CsvSource(
            value = {"fr.uga.m1info.tp5.components.AlbumComponent",
            "fr.uga.m1info.tp5.components.ArtistComponent",
            "fr.uga.m1info.tp5.components.PlaylistComponent",
            "fr.uga.m1info.tp5.components.SongComponent",
            "fr.uga.m1info.tp5.components.UserComponent",
            }
    )
    void verifyCrudStructure(String componentClassName) throws ClassNotFoundException {
        Class<?> component = TestUtils.getClassForNameWithAssertion(componentClassName);

        assertThat(component.getAnnotation(Component.class))
                .as("Le composant est un [@Bean], donc injectable, donc il faut que la class porte l'annotation [@Component]")
                .isNotNull();


        assertThat(component.getDeclaredMethods())
                .as("Dans le composant %s, toutes les fonctions du C.R.U.D ne sont pas implémenté",component.getSimpleName())
                .hasSizeGreaterThanOrEqualTo(4);

        TestUtils.assertionClassHaveDeclaredMethodContainingName(component,"create")
                .as("Dans le composant %s, la fonction update (C) n'existe pas ou ne contient pas [%s]",component.getSimpleName(),"create")
                .hasSizeGreaterThanOrEqualTo(1);

        TestUtils.assertionClassHaveDeclaredMethodContainingName(component,"get")
                .as("Dans le composant %s, la fonction update (R) n'existe pas ou ne contient pas [%s]",component.getSimpleName(),"get")
                .hasSizeGreaterThanOrEqualTo(1);


        TestUtils.assertionClassHaveDeclaredMethodContainingName(component,"update")
                .as("Dans le composant %s, la fonction update (U) n'existe pas ou ne contient pas [%s]",component.getSimpleName(),"update")
                .hasSizeGreaterThanOrEqualTo(1);


        TestUtils.assertionClassHaveDeclaredMethodContainingName(component,"delete")
                .as("Dans le composant %s, la fonction update (D) n'existe pas ou ne contient pas [%s]",component.getSimpleName(),"delete")
                .hasSizeGreaterThanOrEqualTo(1);

        Set<Field> repositoriesDeclared = Arrays.stream(component.getDeclaredFields()).filter(field -> field.getName().toLowerCase().contains("repository")).collect(Collectors.toSet());

        assertThat(repositoriesDeclared)
                .as("Vous devez au moins avoir déclaré le repository")
                .hasSizeGreaterThanOrEqualTo(1);

        repositoriesDeclared.forEach(field -> {
             assertThat(field.getAnnotation(Autowired.class))
                     .as("Vos attributs n'ont pas besoin du @Autowired, vous pouvez faire une injection de dépendance avec lombok via [@RequiredArgConstructor]")
                     .isNull();
            assertThat(field.getModifiers())
                    .as("""
                    
                    Cependant, pour que l'annotation [@RequiredArgConstructor] fonctionne, il faut que les attributs soient [final].
                    Ensuite pour suivre les principes solid, il faut que les champs soient [private]
                    """)
                    .isEqualTo(Modifier.PRIVATE | Modifier.FINAL);
        });
    }
}
