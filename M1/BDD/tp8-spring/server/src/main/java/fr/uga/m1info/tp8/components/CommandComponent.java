package fr.uga.m1info.tp8.components;

import fr.uga.m1info.tp8.domain.models.Command;
import fr.uga.m1info.tp8.exceptions.rest.EmptyCommandRestException;
import fr.uga.m1info.tp8.exceptions.rest.ProductNotFoundRestException;
import fr.uga.m1info.tp8.exceptions.technical.CommandEntityNotFoundException;
import fr.uga.m1info.tp8.exceptions.technical.ProductNotFoundException;
import fr.uga.m1info.tp8.mappers.CommandMapper;
import fr.uga.m1info.tp8.models.CommandEntity;
import fr.uga.m1info.tp8.models.OrderedProductEntity;
import fr.uga.m1info.tp8.repositories.CommandEntityRepository;
import fr.uga.m1info.tp8.repositories.ProductEntityRepository;
import fr.uga.m1info.tp8.requests.CommandAddProductRequest;
import fr.uga.m1info.tp8.requests.CommandCreationRequest;
import fr.uga.m1info.tp8.requests.CommandRemoveProductsRequest;
import fr.uga.m1info.tp8.requests.ProductRequest;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;

import java.util.List;

@Component
@RequiredArgsConstructor
public class CommandComponent {
    private final CommandEntityRepository commandEntityRepository;
    private final CommandMapper commandMapper;
    private final ProductEntityRepository productEntityRepository;
    private final ProductComponent productComponent;

    public Command createCommand(CommandCreationRequest request) throws EmptyCommandRestException, ProductNotFoundException {
        if (request.products() == null || request.products().isEmpty()) {
            throw new EmptyCommandRestException("La commande ne peut pas être vide");
        }

        productComponent.verifyAllProductExist(request.products());

        CommandEntity commandEntity = new CommandEntity();
        // TODO
        return commandMapper.toCommand(commandEntity);
    }
/* TO DO
    public Command addProducts(Long idCommand, CommandAddProductRequest request) throws CommandEntityNotFoundException {
        return null;
    }
*/
/* TO DO
    public Command getCommandById(Long idCommand) throws CommandEntityNotFoundException {
        return null;
    }
*/
/* TO DO
    public Command deleteProducts(Long idCommand, CommandRemoveProductsRequest request) throws CommandEntityNotFoundException {
        return null;
    }
*/
}
