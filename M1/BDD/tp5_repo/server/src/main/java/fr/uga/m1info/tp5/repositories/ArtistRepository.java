package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.enums.GenreMusical;
import fr.uga.m1info.tp5.models.ArtistEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface ArtistRepository extends JpaRepository<ArtistEntity, String> {
    int countAllByGenreMusical(GenreMusical genreMusical);
}