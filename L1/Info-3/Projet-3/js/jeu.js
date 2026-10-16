var canvas = document.createElement("canvas");
var ctx = canvas.getContext("2d");
canvas.width = 512;
canvas.height = 480;

function create_canevas() {document.getElementById("game").appendChild(canvas);}

var bgReady = false;
var bgImage = new Image();
bgImage.onload = function ()
{
    bgReady = true;
};
bgImage.src = "img/background.png";

var herosReady = false;
var herosImage = new Image();
herosImage.onload = function ()
{
    herosReady = true;
};
herosImage.src = "img/hero.png";

var monstreReady = false;
var monstreImage = new Image();
monstreImage.onload = function ()
{
    monstreReady = true;
};
monstreImage.src = "img/monster.png";

//Golem
var golemReady = false;
var golemImage = new Image();
golemImage.onload = function ()
{
    golemReady = true;
}
golemImage.src = "img/Golem/Right/0.png";

var heros =
    {
        speed: 256, // vitesse en pixels par seconde
        x: 0,
        y: 0,
        invincible: false,
        invincible_time: 0, // Temps en nombre de frames
        hit_box: 32,
    };

var monstre =
    {
        //On donne un vitesse de 100 au debut du jeu, et on l'incremente de 1 a chaque fois qu'on attrape un monstre
        speed: 100,
        max_speed: 255,
        x: 0,
        y: 0,
    };

var golem =
    {
        x: 0,
        y: 0,
        speed: 15,
        frame: 0,
        direction: "Down",
        timer: 0,
        animated: false
    }

var monstresAttrapes = 0;

var touchesAppuyees = {}; // Tableau associatif des touches appuyées
var historiqueTouches = ""; // Contient l'histoire des x dernières touches appuyées

// Dictionnaire des touches a executer et des effets de chaque cheat code
var cheat_codes = {
    "ArrowUp/ArrowLeft/ArrowDown/ArrowRight/": function () {monstresAttrapes += 10;reset();},
    "ArrowUp/ArrowDown/ArrowLeft/ArrowRight/": function () {monstre.max_speed=0;},
    "ArrowDown/ArrowDown/ArrowLeft/ArrowRight/ArrowLeft/ArrowRight/": function () {monstresAttrapes += 50;reset();},
    "ArrowUp/ArrowRight/ArrowDown/ArrowLeft/ArrowUp/ArrowRight/ArrowDown/ArrowLeft/": function () {monstreRouges_maxSpeed=0;golem.speed = 1;reset();},
    "ArrowRight/ArrowRight/ArrowLeft/ArrowLeft/ArrowDown/ArrowUp/ArrowDown/ArrowUp/" : function () {heros.invincible = true;heros.invincible_time = 1000},

    "ArrowUp/ArrowUp/ArrowDown/ArrowDown/ArrowLeft/ArrowRight/ArrowLeft/ArrowRight/ArrowUp/ArrowUp/ArrowDown/ArrowDown/ArrowLeft/ArrowRight/ArrowLeft/ArrowRight/":
        function () {heros.invincible = true;heros.invincible_time += 5000;monstreRouges_maxSpeed=0;golem.speed=0;monstre.speed=0;monstresAttrapes+=100;reset();},
};


// Liste des monstres rouge
var monstresRouges = [];
var monstreRouges_maxSpeed = 256;

addEventListener("keydown", function (e)
{
    if(["ArrowLeft", "ArrowUp", "ArrowRight", "ArrowDown"].indexOf(e.key) > -1) {
        e.preventDefault();
        touchesAppuyees[e.key] = true;
        // On ajoute la chaines de caractères correspondant a la touche appuyée dans l'historique
        historiqueTouches += e.key + "/";
        console.log(historiqueTouches);
    }
}, false);

addEventListener("keyup", function (e)
{
    if(["ArrowLeft", "ArrowUp", "ArrowRight", "ArrowDown"].indexOf(e.key) > -1) {
        delete touchesAppuyees[e.key];
    }
}, false);

var reset = function (replace_heros=false)
{
    if (replace_heros)
    {
        heros.x = canvas.width / 2 - 16;
        heros.y = canvas.height / 2 - 16;

        golem.x = canvas.width / 2 - 16;
        golem.y = 64;

        golem.speed = 15;
        monstreRouges_maxSpeed = 256;
        monstre.max_speed = 255;
    }
    // Faire apparaître un monstre au hasard
    monstre.x = 32 + (Math.random() * (canvas.width - 96));
    monstre.y = 32 + (Math.random() * (canvas.height - 96));
    // On augmente la vitesse du monstre de 10 tous les 10 monstres attrapés
    monstre.speed = 100 + Math.floor(monstresAttrapes / 10) * 20;

    // Un monstre rouge apparait au hasard par tranche de 10 monstres attrapés
    monstresRouges = [];
    for (let i = 0; i < Math.floor(monstresAttrapes / 10); i++)
    {
        monstresRouges.push({
            ready: false,
            image: new Image(),
            x: 32 + (Math.random() * (canvas.width - 96)),
            y: 32 + (Math.random() * (canvas.height - 96)),
            // On augmente la vitesse du monstre tous les 10 monstres attrapés
            speed: Math.min(50 + Math.floor(monstresAttrapes / 10) * 20, monstreRouges_maxSpeed),});

        monstresRouges[i].image.onload = function ()
        {monstresRouges[i].ready = true;};
        monstresRouges[i].image.src = "img/monster2.png";
    }

    if(heros.x <= (monstre.x + heros.hit_box) && monstre.x <= (heros.x + heros.hit_box) && heros.y <= (monstre.y + heros.hit_box) && monstre.y <= (heros.y + heros.hit_box)
        || heros.x <= (golem.x + heros.hit_box) && golem.x <= (heros.x + heros.hit_box) && heros.y <= (golem.y + heros.hit_box) && golem.y <= (heros.y + heros.hit_box)
        || monstresRouges.some(monstreRouge => heros.x <= (monstreRouge.x + heros.hit_box) && monstreRouge.x <= (heros.x + heros.hit_box) && heros.y <= (monstreRouge.y + heros.hit_box) && monstreRouge.y <= (heros.y + heros.hit_box)))
    {
        reset();
    }
};

var update = function (modifier)
{
    if ("ArrowUp" in touchesAppuyees) {heros.y -= heros.speed * modifier;}

    if ("ArrowDown" in touchesAppuyees) {heros.y += heros.speed * modifier;}

    if ("ArrowLeft" in touchesAppuyees) {heros.x -= heros.speed * modifier;}

    if ("ArrowRight" in touchesAppuyees) {heros.x += heros.speed * modifier;}

    // On verifie si le joueur a appuyé sur une touche du cheat code
    cheat();

    // Le joueur ne doit pas sortir de l'écran
    no_quit_screen(heros);

    // Y a-t-il contact ?
    if(heros.x <= (monstre.x + heros.hit_box) && monstre.x <= (heros.x + heros.hit_box) && heros.y <= (monstre.y + heros.hit_box) && monstre.y <= (heros.y + heros.hit_box))
    {++monstresAttrapes;reset();}

    // Y a-t-il contact avec un monstre rouge ?
    for (let i = 0; i < monstresRouges.length; i++)
    {if(heros.x <= (monstresRouges[i].x + heros.hit_box) && monstresRouges[i].x <= (heros.x + heros.hit_box) && heros.y <= (monstresRouges[i].y + heros.hit_box) && monstresRouges[i].y <= (heros.y + heros.hit_box) && !heros.invincible)
        {monstresAttrapes--;reset();}}

    // y a-t-il contact avec le golem ?
    if(heros.x <= (golem.x + heros.hit_box) && golem.x <= (heros.x + heros.hit_box) && heros.y <= (golem.y + heros.hit_box) && golem.y <= (heros.y + heros.hit_box) && !heros.invincible)
    {monstresAttrapes = 0;reset(true);}

    // On applique l'invincibilité
    if (heros.invincible) {
        herosImage.src = "img/hero_halo.png";heros.hit_box = 64;heros.invincible_time--;
        if (heros.invincible_time <= 0) {heros.invincible = false;herosImage.src = "img/hero.png";heros.hit_box = 32;}}

    move_monstre_vert(modifier);
    move_monstre_rouge(modifier);
    move_golem(modifier);

};

function move_golem(modifier)
{
    /* Le golem se déplace vers le héros */
    if (golem.x < heros.x) {golem.x += golem.speed * modifier;animate_golem("Right");}

    if (golem.x > heros.x) {golem.x -= golem.speed * modifier;animate_golem("Left");}4

    if (golem.y < heros.y) {golem.y += golem.speed * modifier;}

    if (golem.y > heros.y) {golem.y -= golem.speed * modifier;}

    no_quit_screen(golem);
}

function cheat()
{
    if (check_historique_in_cheat_codes() === 1)
    {
        // On applique le cheat code
        cheat_codes[historiqueTouches].apply();
        // On réinitialise l'historique
        historiqueTouches = "";
    }
    else if (check_historique_in_cheat_codes() === 0)
    {
        // On réinitialise l'historique
        historiqueTouches = "";
    }
}

function check_historique_in_cheat_codes()
{
    // Renvoie 1 si l'historique de touches appuyées correspond à un cheat code
    // Renvoie -1 si l'historique de touches appuyées correspond à un début de cheat code
    // Renvoie 0 sinon

    // On parcourt les cheat codes
    for (let i = 0; i < Object.keys(cheat_codes).length; i++)
    {
        // Si l'historique de touches appuyées correspond à un cheat code
        if (historiqueTouches === Object.keys(cheat_codes)[i])
        {
            return 1;
        }
        // Si l'historique de touches appuyées correspond à un début de cheat code
        else if (historiqueTouches === Object.keys(cheat_codes)[i].substring(0, historiqueTouches.length))
        {
            return -1;
        }
    }
    return 0;
}

function animate_golem(direction)
{
    golem.timer += 1;

    if (golem.timer > 50 && golem.animated === false)
    {

        if (direction !== golem.direction)
        {
            golem.direction = direction;
            golem.frame = 0;
            golem.timer = 0;
        }

        golem.animated = true;
        golem.timer = 0;

        if (direction === "Right") {golemImage.src = "img/Golem/Right/" + golem.frame + ".png";}
        else {golemImage.src = "img/Golem/Left/" + golem.frame + ".png";}
        golem.frame = (golem.frame + 1) % 7;
    }
}

function move_monstre_rouge(modifier)
{
    /* Les monstres rouges se déplacent vers le héros */
    for (let i = 0; i < monstresRouges.length; i++)
    {
        if (monstresRouges[i].x < heros.x)
        {
            monstresRouges[i].x += monstresRouges[i].speed * modifier;
        }
        if (monstresRouges[i].x > heros.x)
        {
            monstresRouges[i].x -= monstresRouges[i].speed * modifier;
        }
        if (monstresRouges[i].y < heros.y)
        {
            monstresRouges[i].y += monstresRouges[i].speed * modifier;
        }
        if (monstresRouges[i].y > heros.y)
        {
            monstresRouges[i].y -= monstresRouges[i].speed * modifier;
        }
    }

    /* Les monstres rouges ne doivent pas sortir de l'écran */
    for (let i = 0; i < monstresRouges.length; i++)
    {
        no_quit_screen(monstresRouges[i]);
    }
}

//Le monstre vert s'éloigne du héros
function move_monstre_vert(modifier)
{

    if (monstre.x < heros.x)
    {
        monstre.x -= Math.min(monstre.max_speed, monstre.speed) * modifier;
    }
    if (monstre.x > heros.x)
    {
        monstre.x += Math.min(monstre.max_speed, monstre.speed) * modifier;
    }
    if (monstre.x === heros.x)
    {
        monstre.x += (Math.random() * 2 - 1) * Math.min(monstre.max_speed, monstre.speed) * modifier;
    }
    if (monstre.y < heros.y)
    {
        monstre.y -= Math.min(monstre.max_speed, monstre.speed) * modifier;
    }
    if (monstre.y > heros.y)
    {
        monstre.y += Math.min(monstre.max_speed, monstre.speed) * modifier;
    }
    if (monstre.y === heros.y)
    {
        monstre.y += (Math.random() * 2 - 1) * Math.min(monstre.max_speed, monstre.speed) * modifier;
    }

    /* Le monstre vert ne doit pas sortir de l'écran */
    no_quit_screen(monstre);
}

function no_quit_screen(objet)
{
    if (objet.x < 32)
    {
        objet.x = 32;
    }
    if (objet.y < 32)
    {
        objet.y = 32;
    }
    if (objet.x > canvas.width - 64)
    {
        objet.x = canvas.width - 64;
    }
    if (objet.y > canvas.height - 64)
    {
        objet.y = canvas.height - 64;
    }
}

var render = function ()
{
    if (bgReady)
    {
        ctx.drawImage(bgImage, 0, 0);
    }

    if (herosReady)
    {
        ctx.drawImage(herosImage, heros.x, heros.y);
    }

    if (monstreReady)
    {
        ctx.drawImage(monstreImage, monstre.x, monstre.y);
    }

    /* Affichage des monstres rouges */
    for (let i = 0; i < monstresRouges.length; i++)
    {
        if (monstresRouges[i].ready)
        {
            ctx.drawImage(monstresRouges[i].image, monstresRouges[i].x, monstresRouges[i].y);
        }
    }

    //Affichage du golem
    if (golemReady)
    {
        ctx.drawImage(golemImage, golem.x, golem.y);
        golem.animated = false;
    }

    // Score
    ctx.fillStyle = "rgb(250, 250, 250)";
    ctx.font = "24px Helvetica";
    ctx.textAlign = "left";
    ctx.textBaseline = "top";
    ctx.fillText( " Points : " + monstresAttrapes, 32, 32);
};

var main = function ()
{
    var now = Date.now();
    var delta = now - then;
    update(delta / 1000);
    render();
    then = now;
};

reset(true);
var then = Date.now();
setInterval(main, 1); // Executer aussi vite que possible
