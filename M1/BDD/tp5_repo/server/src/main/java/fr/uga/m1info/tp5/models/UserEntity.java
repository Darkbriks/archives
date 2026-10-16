package fr.uga.m1info.tp5.models;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToMany;
import jakarta.validation.constraints.Email;
import lombok.*;

import java.util.Objects;
import java.util.Set;

@Entity
@Setter
@Getter
@Builder
@NoArgsConstructor
@AllArgsConstructor
public class UserEntity {
    @Id
    private String name;
    @Email
    private String mail;

    @OneToMany
    @JoinColumn(referencedColumnName = "name")
    private Set<PlaylistEntity> playlistEntities;

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        UserEntity that = (UserEntity) o;
        return Objects.equals(getName(), that.getName()) && Objects.equals(getMail(), that.getMail()) && Objects.equals(getPlaylistEntities(), that.getPlaylistEntities());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), getMail(), getPlaylistEntities());
    }
}
