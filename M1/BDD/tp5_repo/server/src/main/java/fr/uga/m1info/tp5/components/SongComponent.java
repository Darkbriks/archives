package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.models.SongEntity;
import fr.uga.m1info.tp5.repositories.SongRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

import java.time.Duration;

@Component
@RequiredArgsConstructor
public class SongComponent {
    private final SongRepository songRepository;
    
    public SongEntity getSongEntity(String title){
        return songRepository.findById(title).orElseThrow();
    }

    public SongEntity createSongEntity(SongEntity playlistEntity){
        return songRepository.save(playlistEntity);
    }

    public SongEntity updateSongEntity(SongEntity newSongEntity){
        SongEntity songEntity = songRepository.findById(newSongEntity.getTitle()).orElseThrow();
        songEntity.setDuration(newSongEntity.getDuration());
        songEntity.setAlbumEntity(newSongEntity.getAlbumEntity());
        songEntity.setArtistEntity(newSongEntity.getArtistEntity());
        return songRepository.save(songEntity);
    }

    public void deleteSongEntity(String title){
        songRepository.deleteById(title);
    }

    public SongEntity findSongEntityIsInDurationInterval(Duration start,Duration end){
        return songRepository.findSongEntityByDurationBetween(start,end);
    }
}
