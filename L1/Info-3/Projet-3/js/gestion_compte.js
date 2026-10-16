var player_name = "";

function set_player_name() {
    player_name = document.getElementById("pseudo").value;

    // recuperer les donnees du joueur dans la base de donnees
}


function display_login_form() {
    // afficher le formulaire de connexion
    // et un bouton pour revenir au menu principal

    document.getElementById("compte").innerHTML =
        "<form id='login_form' action='javascript:login()'> " +
        "<input type='text' id='pseudo' placeholder='Pseudo' /> " +
        "<input type='password' id='password' placeholder='Mot de passe' /> " +
        "<input type='submit' value='Connexion' /> " +
        "</form>" +
        "<button onclick='display_main_menu()'>Retour</button>";
}

function display_create_account_form() {
    // afficher le formulaire d'inscription
    // et un bouton pour revenir au menu principal

    document.getElementById("compte").innerHTML =
        "<form id='create_account_form' action='javascript:create_account()'> " +
        "<input type='text' id='pseudo' placeholder='Pseudo' /> " +
        "<input type='email' id='email' placeholder='Email' /> " +
        "<input type='password' id='password' placeholder='Mot de passe' /> " +
        "<input type='password' id='password_confirm' placeholder='Confirmer le mot de passe' /> " +
        "<input type='submit' value='Inscription' /> " +
        "</form>" +
        "<button onclick='display_main_menu()'>Retour</button>";
}

function display_main_menu() {
    // afficher le menu principal
    // et un bouton pour se connecter

    document.getElementById("compte").innerHTML =
        "<form id='connexion'> " +
        "<h2>J'ai deja un compte</h2> " +
        "<button type='button' id='btnConnexion' onClick='display_login_form()'>Connexion</button> " +
        "<h2>Je n'ai pas de compte</h2> " +
        "<button type='button' id='btnInscription' onclick='display_create_account_form()'>Inscription</button> " +
        "<h2>Je veux jouer en tant qu'invite</h2> " +
        "<button type='button' id='btnInvité' onclick='play()'>Invité</button> " +
        "</form>";
}

function create_account() {
    // verifier si le joueur existe dans la base de donnees
    // si oui, afficher un message d'erreur
    // sinon, creer le joueur dans la base de donnees
    // et afficher la page de jeu

    alert("traitement de l'inscription");

    if (document.getElementById("password").value === document.getElementById("password_confirm").value) {
        // appeler le script php avec les parametres action, pseudo, password, email
        // et recuperer le resultat dans une variable
        // si le resultat est "ok", afficher la page de jeu
        // sinon, afficher un message d'erreur
        var pseudo = document.getElementById("pseudo").value;
        var password = document.getElementById("password").value;
        var email = document.getElementById("email").value;

        var xhr = new XMLHttpRequest();
        xhr.open("POST", "http://antoine-univ-littoral.alwaysdata.net/Serveur/", true);
        xhr.setRequestHeader("Content-Type", "application/json");
        xhr.onreadystatechange = function() {
            if (xhr.readyState === 4 && xhr.status === 200) {
                alert(xhr.responseText);
            }
        };
        var params = {pseudo: pseudo, password: password, email: email};
        xhr.send(JSON.stringify(params));
        alert("fin traitement de l'inscription");

    } else {
        alert("les mots de passe ne correspondent pas");
    }
}

function play()
{
    create_canevas();
    document.getElementById("compte").innerHTML = "";
}

function login() {
    // verifier si le joueur existe dans la base de donnees
    // si oui, afficher la page de jeu
    // sinon, afficher un message d'erreur


}

display_main_menu();