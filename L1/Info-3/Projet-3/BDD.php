<?php
//Recuperer les données du formulaire
$action = $_POST['action'];
$pseudo = $_POST['pseudo'];
$mdp = $_POST['mdp'];
$email = $_POST['email'];

//Se connecter à la base de données
$servername = "monserveur";
$username = "monnom";
$password = "monmotdepasse";
$dbname = "maBDD";

$conn = new mysqli($servername, $username, $password, $dbname);

//Vérifie que la connexion à la base de données a réussi
if ($conn->connect_error) {
    die('Erreur de connexion : ' . $conn->connect_error);}

//Si l'action est 0, on veut insérer un nouvel utilisateur
if ($action == 0) {
    //On vérifie que l'utilisateur n'existe pas déjà
    $sql = "SELECT * FROM site_incomplet_users WHERE pseudo = '$pseudo'";

    if ($conn->query($sql) === TRUE) {
        echo "1";
    }// l'erreur 1 corresond a un pseudo deja utilisé

    else {
        //On verifie que l'email n'est pas déjà utilisé
        $sql = "SELECT * FROM site_incomplet_users WHERE email = '$email'";

        if ($conn->query($sql) === TRUE) {
            echo "2";
        }// l'erreur 2 corresond a un mail deja utilisé

        else {
            //On hash le mot de passe
            $mdp = password_hash($mdp, PASSWORD_DEFAULT);

            //On insère l'utilisateur
            $sql = "INSERT INTO site_incomplet_users (pseudo, mdp, email) VALUES ('$pseudo', '$mdp', '$email')";
            if ($conn->query($sql) === TRUE) {
                echo "0";// le code 0 correspond a un utilisateur inséré
            } else {
                echo "3";// l'erreur 3 correspond a une erreur de connexion
            }
        }

        //On envoie un mail de confirmation
        $to = $email;
        $subject = "Confirmation d'inscription";
        $message = "Bonjour $pseudo,\n\nNous vous confirmons la creation de votre compte et vous remercions de l'interet que vous porter a notre site.\n\nCordialement,\n\nL'équipe Darkbriks Studio";
        $headers = "From: Une adresse mail\r\n" .
            "Reply-To: " . $email . "\r\n" .
            "X-Mailer: PHP/" . phpversion();

        mail($to, $subject, $message, $headers);
    }
}

//Si l'action est 1, on veut vérifier si l'utilisateur existe
if ($action == 1) {
    //On vérifie que l'utilisateur existe
    $sql = "SELECT * FROM site_incomplet_users WHERE pseudo = '$pseudo'";

    if ($conn->query($sql) === TRUE)
    {echo "Ce pseudo n'existe pas";}

    else {
        //On vérifie que le mot de passe est correct
        $sql = "SELECT * FROM site_incomplet_users WHERE pseudo = '$pseudo'";
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        $mdp_hash = $row['mdp'];

        if (password_verify($mdp, $mdp_hash)) {
            echo "Mot de passe correct";
        } else {
            echo "Mot de passe incorrect";
        }
    }
}

//Fermer la connexion
$conn->close();