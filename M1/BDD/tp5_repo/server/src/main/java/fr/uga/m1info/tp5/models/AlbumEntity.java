package fr.uga.m1info.tp5.models;

import jakarta.persistence.*;
import lombok.*;

import java.sql.Date;
import java.util.Set;

@Entity
@Getter
@Setter
@Builder
@NoArgsConstructor
@AllArgsConstructor
@EqualsAndHashCode
public class AlbumEntity {
    @Id
    private String title;

    private Date releaseDate;

    @OneToMany(mappedBy = "albumEntity",cascade = CascadeType.ALL)
    private Set<SongEntity> songEntities;

    @ManyToOne
    private ArtistEntity artistEntity;
}
