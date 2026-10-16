package fr.uga.m1info.tp8.components;

import fr.uga.m1info.tp8.domain.models.Client;
import fr.uga.m1info.tp8.exceptions.rest.EmailInvalidFormatRestException;
import fr.uga.m1info.tp8.exceptions.technical.ClientEntityNotFoundException;
import fr.uga.m1info.tp8.mappers.ClientMapper;
import fr.uga.m1info.tp8.repositories.ClientEntityRepository;
import fr.uga.m1info.tp8.requests.ClientCreationRequest;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

@Component
@RequiredArgsConstructor
public class ClientComponent {
    private final ClientEntityRepository clientEntityRepository;
    private final ClientMapper clientMapper;

    public Client getClient(Long idClient) throws ClientEntityNotFoundException {
        return clientMapper.toClient(clientEntityRepository.findById(idClient)
                .orElseThrow(() -> new ClientEntityNotFoundException(String.format("Le client [%s] n'existe pas", idClient))));
    }

    public Client createClient(ClientCreationRequest request) throws EmailInvalidFormatRestException {
        if (!request.email().matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$")) {
            throw new EmailInvalidFormatRestException(String.format("L'adresse email [%s] n'est pas au bon format", request.email()));
        }
        return clientMapper.toClient(clientEntityRepository.save(
                clientMapper.toEntity(request)
        ));
    }
}
