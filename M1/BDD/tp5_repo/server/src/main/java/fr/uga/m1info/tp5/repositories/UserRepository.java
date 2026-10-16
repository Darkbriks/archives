package fr.uga.m1info.tp5.repositories;

import fr.uga.m1info.tp5.models.UserEntity;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Set;

@Repository
public interface UserRepository extends JpaRepository<UserEntity, String> {
    Set<UserEntity> findAllByMailContaining(String domaine);
}