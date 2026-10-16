package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.models.PlaylistEntity;
import fr.uga.m1info.tp5.models.SongEntity;
import fr.uga.m1info.tp5.repositories.PlaylistRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

import java.util.Set;

@Component
@RequiredArgsConstructor
public class PlaylistComponent{
    private final PlaylistRepository playlistRepository;


    public PlaylistEntity getPlaylistEntity(String name){
        return playlistRepository.findById(name).orElseThrow();
    }

    public PlaylistEntity createPlaylistEntity(PlaylistEntity playlistEntity){
        return playlistRepository.save(playlistEntity);
    }

    public PlaylistEntity updatePlaylistEntity(PlaylistEntity newPlaylistEntity){
        PlaylistEntity playlistEntity = playlistRepository.findById(newPlaylistEntity.getName()).orElseThrow();
        playlistEntity.setSongEntities(newPlaylistEntity.getSongEntities());
        return playlistRepository.save(playlistEntity);
    }

    public void deletePlaylistEntity(String name){
        playlistRepository.deleteById(name);
    }

    public Set<PlaylistEntity> getAllPlaylistEntityWithSong(SongEntity songEntity) {
        return playlistRepository.findAllBySongEntitiesEquals(songEntity);
    }
}
