let list_url = ["Image/Presentation_1.png", "Image/Presentation_2.png", "Image/Presentation_3.png", "Image/Presentation_4.png", "Image/Presentation_5.png", "Image/Presentation_6.png"]
let list_text = ["Profitez du jeu sur votre plateforme préférée.", "Débloquez l'entièreté des DLC du jeu, dont le DLC Kronos 44 : Awakening, qui revient sur les débuts d'Anaïs et d'Elliot.", "Télécharger un magnifique artbook, l'album du jeu, ainsi que de splendides fonds d'écran.", "Complètez votre collection avec le jeu en version physique, ainsi que le magnifique artbook, un steelbook, une figurine de 30cm d'Anaïs, ainsi que l'album du jeu."]

function galerie(sens)
{
    if (sens===1) {list_url.push(list_url.shift());}
    else {list_url.unshift(list_url.pop());}

    document.getElementById('Img_galerie').src = list_url[0]
}

function add_url()
{
    list_url.push(document.getElementById("url").value)
    document.getElementById("url").value = "URL de l'image"
    galerie(-1)
}

/* Fonction qui selectione tous les element d'une classe et modifie leurs css */
function select_class(class_name, css, pas=1)
{
    let list = document.getElementsByClassName(class_name)
    for (let i=0; i<list.length; i+=pas)
    {
        list[i].style.cssText = css
    }
}

/* Fonction pour injecter du code html dans une page */
function inject_html(arg)
{
    let list = arg.split("/-/")
    let txt = list[2].split("_")
    let txt_str = ""
    for (let i=0; i<txt.length; i++) {txt_str += txt[i] + " "}
    if (list[3]==="false") {document.getElementById(list[0]).innerHTML = "<button class='button' onclick=inject_html('"+ list[0] +"/-/"+ list[1] +"/-/"+ list[2].toString() +"/-/"+ true +"')>"+txt_str+"</button><p class='text'>"+ list_text[list[1]] +"</p>"}
    else {document.getElementById(list[0]).innerHTML = "<button class='button' onclick=inject_html('"+ list[0] +"/-/"+ list[1] +"/-/"+ list[2].toString() +"/-/"+ false +"')>"+txt_str+"</button>"}
}

// Permet le decalage des images et du texte une fois sur deux
select_class("promo__wrapper__media", "grid-column-start: 2; grid-column-end: 6;",2)
select_class("promo__wrapper__content", "grid-column-start: 1; grid-column-end: 3;",2)