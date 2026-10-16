package fr.uga.m1info.tp5.components;

import fr.uga.m1info.tp5.models.UserEntity;
import fr.uga.m1info.tp5.repositories.UserRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

import java.util.Set;

@Component
@RequiredArgsConstructor
public class UserComponent {
    private final UserRepository userRepository;

    public UserEntity getUser(String name) {
        return userRepository.findById(name).orElseThrow();
    }

    public UserEntity createUser(UserEntity user){
        return userRepository.save(user);
    }

    public UserEntity updateEmail(UserEntity user){
        UserEntity userEntity = userRepository.findById(user.getName()).orElseThrow();
        userEntity.setMail(user.getMail());
        return userRepository.save(userEntity);
    }

    public void deleteUser(String name){
        userRepository.deleteById(name);
    }

    public Set<UserEntity> findUserIsInDomain(String domaine){
        return userRepository.findAllByMailContaining(domaine);
    }
}

    
