package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.models.SongEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.time.Duration;
import java.util.Set;

@Repository
public interface SongRepository extends JpaRepository<SongEntity, String> {
    SongEntity findSongEntityByDurationBetween(Duration start, Duration end);
}