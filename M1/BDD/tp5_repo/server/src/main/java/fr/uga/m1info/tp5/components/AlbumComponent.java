package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.models.AlbumEntity;
import fr.uga.m1info.tp5.repositories.AlbumRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

@Component
@RequiredArgsConstructor
public class AlbumComponent {
    private final AlbumRepository albumRepository;

    public AlbumEntity getAlbumEntity(String title){
        return albumRepository.findById(title).orElseThrow();
    }

    public AlbumEntity createAlbum(AlbumEntity entity){
        return albumRepository.save(entity);
    }

    public AlbumEntity updateAlbum(AlbumEntity newAlbumEntity){
        AlbumEntity albumEntity = albumRepository.findById(newAlbumEntity.getTitle()).orElseThrow();
        albumEntity.setReleaseDate(newAlbumEntity.getReleaseDate());
        albumEntity.setArtistEntity(newAlbumEntity.getArtistEntity());
        albumEntity.setSongEntities(newAlbumEntity.getSongEntities());
        return albumRepository.save(albumEntity);
    }

    public void deleteAlbum(String title){
        albumRepository.deleteById(title);
    }
}
