package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.models.AlbumEntity;
import fr.uga.m1info.tp5.models.SongEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.time.Duration;

@Repository
public interface AlbumRepository extends JpaRepository<AlbumEntity, String> {
}