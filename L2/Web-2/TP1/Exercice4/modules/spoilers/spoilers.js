let spoilerButton = document.querySelectorAll('.spoiler-button')

spoilerButton.forEach(button => {
    button.setAttribute('onclick', 'toggleSpoiler(true, this)')
})

function toggleSpoiler(toggle, spoilerButton)
{

    if (toggle)
    {
        let spoilers = spoilerButton.parentElement.parentElement.querySelectorAll('.spoiler-content')
        spoilerButton.innerHTML = "Cacher le spoiler"
        spoilers.forEach(spoiler => {
            spoiler.classList.remove('spoiler-content')
            spoiler.classList.add('spoiler-visible')
        })
        spoilerButton.setAttribute('onclick', 'toggleSpoiler(false, this)')
    }
    else
    {
        let spoilers = spoilerButton.parentElement.parentElement.querySelectorAll('.spoiler-visible')
        spoilerButton.innerHTML = "Afficher le spoiler"
        spoilers.forEach(spoiler => {
            spoiler.classList.remove('spoiler-visible')
            spoiler.classList.add('spoiler-content')
        })
        spoilerButton.setAttribute('onclick', 'toggleSpoiler(true, this)')
    }
}