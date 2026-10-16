package fr.uga.m1info.tp8.services;

import fr.uga.m1info.tp8.components.CommandComponent;
import fr.uga.m1info.tp8.domain.models.Command;
import fr.uga.m1info.tp8.exceptions.rest.EmptyCommandRestException;
import fr.uga.m1info.tp8.exceptions.rest.ProductNotFoundRestException;
import fr.uga.m1info.tp8.exceptions.technical.ProductNotFoundException;
import fr.uga.m1info.tp8.requests.CommandAddProductRequest;
import fr.uga.m1info.tp8.requests.CommandCreationRequest;
import fr.uga.m1info.tp8.requests.CommandRemoveProductsRequest;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class CommandService {
    private final CommandComponent commandComponent;

    public Command createCommand(CommandCreationRequest request) {
        try {
            return commandComponent.createCommand(request);
        } catch (ProductNotFoundException e) {
            throw new ProductNotFoundRestException(e.getMessage());
        }
    }

    // TODO 🚧 
    public Command addProducts(Long idCommand, CommandAddProductRequest request) {
        return null;
    }

    // TODO 🚧 
    public Command removeProducts(Long idCommand, CommandRemoveProductsRequest request) {
        return null;
    }
}
