package fr.uga.m1info.tp5.models;

import fr.uga.m1info.tp5.enums.GenreMusical;
import jakarta.persistence.*;
import lombok.*;

import java.util.Set;

@Entity
@Setter
@Getter
@Builder
@NoArgsConstructor
@AllArgsConstructor
@EqualsAndHashCode
public class ArtistEntity {
    @Id
    private String name;

    private String biography;

    @Enumerated(EnumType.STRING)
    private GenreMusical genreMusical;

    @OneToMany(mappedBy = "artistEntity",cascade = CascadeType.ALL)
    private Set<AlbumEntity> albumEntities;
}
