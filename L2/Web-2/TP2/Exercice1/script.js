let images = []
images.push("images/610747.jpg")
images.push("images/888509.jpg")
images.push("images/695524.jpg")
images.push("images/600918.jpg")
images.push("images/216856.jpg")

let thumbs = []
let currentThumb = 0

let overlay = null
let playTimer = null

function createThumbs() {
    let _thumbs = document.getElementById("thumbs-list")
    images.forEach(image => {
        let div = document.createElement('div')
        let img = document.createElement('img')
        img.setAttribute('src', image)
        img.setAttribute('alt', image)
        div.classList.add('thumb')
        div.appendChild(img)
        _thumbs.appendChild(div)
        div.addEventListener('click', () => {
            displayThumb(div)
        })
        thumbs.push(div)
    })
}

/**
 * Récupération de la chaine correspondant à l'attribut 'src' de la balise 'img' du '.thumb'
 * @param thumb : un élément ".thumb"
 * @returns le contenu de l'attribut 'src'
 */
function getSrc(thumb){
    return thumb.querySelector('img').getAttribute('src')
}

/**
 * Affiche dans #display-image l'image contenue dans thumb
 * @param thumb : l'élément contenant l'image à afficher
 */
function displayThumb(thumb){
    let display = document.getElementById('display-image')
    display.setAttribute('src', getSrc(thumb))
    thumbs.forEach(thumb => {
        thumb.classList.remove('selected')
    })
    thumb.classList.add('selected')
    currentThumb = thumbs.indexOf(thumb)
    thumb.scrollIntoView({behavior: "smooth", block: "nearest", inline: "center"})
}

/**
 * Fais passer l'affichage dans #diplay-image au thumb suivant dans thumbs
 */
function displayNextThumb(){
    currentThumb = (currentThumb + 1) % thumbs.length
    displayThumb(thumbs[currentThumb])
}

/**
 * Crée un fade-in sur l'image affichée grâce à la propriété 'opacity' et a setTimeout
 * par défaut, le fade durera 1000ms
 */
function fadeIn(callback, delay = 1000){
    let display = document.getElementById('display-image')
    display.style.opacity = 0
    setTimeout(() => {
        display.style.opacity = 1
        callback()
    }, delay)

}

/**
 * Crée un timer avec setInterval, et fait s'exécuter displayNextThumb() toutes les 'elay' ms
 * On le fixera à 3000ms par défaut
 */
function play(delay = 3000){
    playTimer = setTimeout(() => {
        displayNextThumb()
        play(delay)
    }, delay)
}

/**
 * arrête et nettoie le timer
 */
function stop(){
    clearInterval(playTimer)
    playTimer = null
}

/**
 * Crée un timer si aucun n'existe, sinon le stoppe
 */
function togglePlay(){
    if (playTimer == null) {
        play()
        overlay.innerHTML = "<button id='pause-button'><img src='images/pause-fill.svg' alt='pause'></button>"
    }
    else {
        stop()
        overlay.innerHTML = "<button id='play-button'><img src='images/play-fill.svg' alt='play'></button>"
    }
}

addEventListener('DOMContentLoaded', () => {
    createThumbs()
    displayThumb(thumbs[0])

    overlay = document.getElementById('overlay')
    overlay.innerHTML = "<button id='play-button'><img src='images/play-fill.svg' alt='play'></button>"
    overlay.addEventListener('click', () => {
        togglePlay()
    })
})