package fr.uga.m1info.tp8.services;

import fr.uga.m1info.tp8.components.ClientComponent;
import fr.uga.m1info.tp8.domain.models.Client;
import fr.uga.m1info.tp8.domain.models.Command;
import fr.uga.m1info.tp8.exceptions.rest.ClientNotFoundRestException;
import fr.uga.m1info.tp8.exceptions.rest.EmailInvalidFormatRestException;
import fr.uga.m1info.tp8.exceptions.technical.ClientEntityNotFoundException;
import fr.uga.m1info.tp8.requests.ClientCreationRequest;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.Set;

@Service
@RequiredArgsConstructor
public class ClientService {
    private final ClientComponent clientComponent;

    public Client createClient(ClientCreationRequest request){
        return clientComponent.createClient(request);
    }

    public Set<Command> getAllCommandByClient(Long idClient) {
        try {
            return clientComponent.getClient(idClient).getCommands();
        } catch (ClientEntityNotFoundException e) {
            throw new ClientNotFoundRestException(
                    e.getMessage());
        }
    }
}
