package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.models.PlaylistEntity;
import fr.uga.m1info.tp5.models.SongEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Set;

@Repository
public interface PlaylistRepository extends JpaRepository<PlaylistEntity, String> {
    Set<PlaylistEntity> findAllBySongEntitiesEquals(SongEntity songEntity);
}
