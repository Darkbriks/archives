let spoilerContent = document.querySelectorAll('.spoiler')
spoilerContent.forEach(content => {
    let contentHTML = content.innerHTML
    content.innerHTML = `<button class="spoiler-button">Afficher le spoiler</button><div class="spoiler-content">${contentHTML}</div>`
})

let spoilerButton = document.querySelectorAll('.spoiler-button')

spoilerButton.forEach(button => {
    button.setAttribute('onclick', 'toggleSpoiler(this, this.nextElementSibling)')
})

function toggleSpoiler(spoilerButton, element)
{
    spoilerButton.classList.replace('spoiler-button', 'spoiler-content')
    element.classList.replace('spoiler-content', 'spoiler-visible')
}