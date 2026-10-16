let state = 0; //int qui contient l'etat de la page. 0 si rien n'est ouvert, 1 si escrime est ouvert...
let trailer = ["Video/Trailer_AC_unity.mp4", "Video/Trailer_ME3.mp4", "Video/Trailer_AC3.mp4", "Video/Trailer_SWJS.mp4"]
let carousel_image = [["https://www.youtube.com/embed/yj-f6JF71ms", 2], ["Image/Kronos_44__3.jpg", 1], ["https://www.youtube.com/embed/4V8xy_iL4EE",2], ["https://www.youtube.com/embed/w4UnoC2dh4A", 2], ["https://www.youtube.com/embed/z6sdX9AM_o0", 2]];

function escrime() 
{
    remove_elt_from_class("content");
    
    if (state === 1)
    {
        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";
        state = 0;
    }
    else 
    {
        state = 1;
    
        document.body.style.backgroundImage = "url('Image/Escrime_Background.jpg')";
        
        document.getElementById("escrime").innerHTML = "<p class='font'>Je pratique depuis août 2021 le fleuret au Cercle des Armes de Calais. </p>" +
            "<p class='font'>Le fleuret est l'une des 4 armes reconnues par la Fédération Internationale d'Escrime, avec l'épée, le sabre et le sabre laser." +
            "C'est l'une des deux armes conventionelles avec le sabre. Cela signifie qu'il y a une \"Convention\", c'est à dire un ensemble de régles qui permettent de départager " +
            "les deux adversaires en cas de touche simultanée.</p>";
    }
}

function dev_jeu()
{
    remove_elt_from_class("content");

    if (state === 2)
    {
        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";
        state = 0;
    }
    else
    {
        state = 2;

        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";

        document.getElementById("dev_jeu").innerHTML = "<p>J'ai commencé à programmer des petits jeux en seconde en utilisant le moteur graphique Unity et le C#. J'ai par exemple réalisé un petit marble run, un protoype de jeu multijoueurs ou encore un prototype de système d'escalade similaire à celui du reboot de Tomb Raider en 2013. " +
            "Puis, en terminale, j'ai participé au //lien CNRD en créant un jeu complet sur Unity, nommé Kronos 44, en respectant le thème \"La fin de la guerre : Les opérations, les répressions, les déportations et la fin du IIIe Reich (1944-1945)\". " +
            "Le jeu a d'ailleurs été récompensé par le département du Pas de Calais et l'Académie de Lille. Durant mon année de terminale, j'ai également appris à utiliser Unreal Engine 4, ainsi que le C++ et le Blueprint. " +
            "Je suis actuellement en train de faire une nouvelle version de Kronos 44, mais en utilisant cette fois le moteur UE4, pour apporter de meilleurs graphismes, plus de gameplay d'histoire et de lore, ainsi que de meilleures finitions au jeu.</p>" +
            "<p>Voici quelques images et vidéos de projet sur lequels j'ai travaillé :</p>" +
            "<div id='caroussel'><button onclick=caroussel(-1)><p>\<</p></button>" +
            "<img id='image' alt='' src=\""+carousel_image[1][0]+"\">" +
            "<button onclick=caroussel(1)><p>\></p></button></div>";}
}

function jeu_video()
{
    remove_elt_from_class("content");

    if (state === 3){
        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";
        state = 0;}
    else {
        state = 3;

        playing_trailer();
        document.getElementById('jeu_video').innerHTML = "<p class='font'>Je joue depuis quelques années à differents jeux vidéos. Mes styles préférés sont les jeux action/aventure/infiltration à la troisième personne. Je joue principalement à des jeux solos" +
            ", mais il m'arrive également de jouer à des jeux multijoueurs, comme par exemple League of Legends, avec des amis. Mes licences préférées sont Assassin's Creed, Mass Effect et Tomb Raider, " +
            "mais je suis également un grand fan des licences Horizon, Jedi Fallen Order, The Last Of Us et bien d'autres encore !</p>";}
}

function musique()
{
    remove_elt_from_class("content");

    if (state === 4)
    {
        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";
        state = 0;
    }
    else 
    {
        state = 4;

        document.body.style.backgroundImage = "url('Image/Acceuil_Background.jpg')";

        document.getElementById('musique').innerHTML = "<p>J'écoute principalement les OST des films et séries que je regarde ou des jeux auxquels je joue.</p>" +
            "<p>Voici quelques unes de mes musiques préférées :</p>" +
            "<button onclick=play_video(\"Video/Get_Jinx_League_of_Legends.mp4\")>Get Jinx from LoL</button>" +
            "<button onclick=play_video(\"Video/Mass_Effect.mp4\")>Mass Effect Song by Malukah</button>" +
            "<button onclick=play_video(\"Video/Shaka_Ponk_Im_picky.mp4\")>Im Picky by Shaka Ponk</button>" +
            "<button onclick=play_video(\"Video/Ezios_Family.mp4\")>Assassin's Creed Theme remix by Møme</button>" +
            "<button onclick=play_video(\"Video/Saint_Saens_Danse_Macabre.mp4\")>Danse Macabre by Radio France</button>";
            //'<audio id="audio">' + //controls
    }
}

function remove_elt_from_class(_class)
{
     let  elt = document.getElementsByClassName(_class);
     for (let i=0; i<elt.length; i++) {elt[i].innerHTML="";}
    video_end();
}

function play_video(video)
{
    document.getElementById('video').innerHTML = "<video id='video_player'><source src=''></video>" +
        "<button id='sound_button' onclick=gestion_son()>Désactiver le son</button>";
    document.getElementById("video_player").src=video;
    document.getElementById("video_player").play();
    document.getElementById("video_player").addEventListener("ended", video_end);
}

function gestion_son() 
{
    document.getElementById("video_player").muted = !document.getElementById("video_player").muted;
    if (document.getElementById("sound_button").textContent === "Activer le son")
        {document.getElementById("sound_button").textContent = "Désactiver le son";}
    else 
        {document.getElementById("sound_button").textContent = "Activer le son";}
}

function video_end()
{
    document.getElementById('video').innerHTML = "";
}

function playing_trailer()
{
    document.getElementById('video').innerHTML = "<video id='video_player'><source src=''></video><button id='sound_button' onclick=gestion_son()>Désactiver le son</button>";
    let elt = trailer.shift();
    trailer.push(elt);
    document.getElementById("video_player").src=elt;
    document.getElementById("video_player").play();
    document.getElementById("video_player").addEventListener("ended", playing_trailer);
}

function caroussel(sens)
{
    if (sens===1) {carousel_image.push(carousel_image.shift());}
    else {carousel_image.unshift(carousel_image.pop());}

    if (carousel_image[1][1] === 1) 
    {document.getElementById('caroussel').innerHTML = 
        "<button onclick=caroussel(-1)><p>\<</p></button>" +
        "<img alt='' src=\""+carousel_image[1][0]+"\">" +
        "<button onclick=caroussel(1)><p>\></p></button>";}
    
    
    else 
    {document.getElementById('caroussel').innerHTML = 
        "<button onclick=caroussel(-1)><p>\<</p></button>" +
        "<iframe src=\""+carousel_image[1][0]+"\"></iframe>" +
        /*"<video controls><source src=\""+carousel_image[1][0]+"\"></video>" +*/
        "<button onclick=caroussel(1)><p>\></p></button>";}
}