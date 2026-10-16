<?php

//Recuperer les données du formulaire
$name = $_POST['name'];
$firsname = $_POST['prenom'];
$email = $_POST['email'];
$message = $_POST['message'];

//Se connecter à la base de données
$servername = "Mon Serveur";
$username = "Mon username";
$password = "Mon mot de passe";
$dbname = "Ma base de donnée";

$conn = new mysqli($servername, $username, $password, $dbname);

//Vérifie que la connexion à la base de données a réussi
if ($conn->connect_error) {
    die('Erreur de connexion : ' . $conn->connect_error);}

//Ajouter les données du formulaire dans la base de données
$sql = "INSERT INTO Contact_form (name, firstname, email, message) VALUES ('$name', '$firsname', '$email', '$message')";
if ($conn-> query($sql) === TRUE) {
    echo "Votre message a bien été envoyé";
} else {
    echo "Erreur : " . $sql . "<br>" . $conn->error;
}

//Fermer la connexion
$conn->close();

//Preparer le mail
$subject = "Confirmation de l'envoi du formulaire de contact";
$message = "Bonjour " . $name . " " . $firsname . ",\n\nNous vous confirmons la réception de votre formulaire de contact, et nous vous remercions de l'intérêt que vous portez à notre site.\nNous vous répondrons dans les plus brefs délais.\n\nCordialement,\n\nL'équipe Darkbriks Studio";
$headers = "From: Darkbriks Studio\r\n" .
"Reply-To: " . $email . "\r\n" .
"X-Mailer: PHP/" . phpversion();

//Envoyer le mail
mail($email, $subject, $message, $headers);

echo "\nLe mail de confirmation a bien ete envoyé";

//Rediriger vers la page d'accueil
header('Location: Site_vitrine/index.html');