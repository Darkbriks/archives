package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.enums.GenreMusical;
import fr.uga.m1info.tp5.models.ArtistEntity;
import fr.uga.m1info.tp5.repositories.ArtistRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

@Component
@RequiredArgsConstructor
public class ArtistComponent {
    private final ArtistRepository artistRepository;

    public ArtistEntity getArtistEntity(String name){
        return artistRepository.findById(name).orElseThrow();
    }

    public ArtistEntity createArtistEntity(ArtistEntity playlistEntity){
        return artistRepository.save(playlistEntity);
    }

    public ArtistEntity updateArtistEntity(ArtistEntity newArtistEntity){
        ArtistEntity artistEntity = artistRepository.findById(newArtistEntity.getName()).orElseThrow();
        artistEntity.setBiography(newArtistEntity.getBiography());
        artistEntity.setGenreMusical(newArtistEntity.getGenreMusical());
        artistEntity.setAlbumEntities(newArtistEntity.getAlbumEntities());
        return artistRepository.save(artistEntity);
    }

    public void deleteArtistEntity(String name){
        artistRepository.deleteById(name);
    }

    public int getNumberArtist(GenreMusical genreMusical){
        return artistRepository.countAllByGenreMusical(genreMusical);
    }
}
