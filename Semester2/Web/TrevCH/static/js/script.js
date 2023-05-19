function changeImage() {
    var workdir = window.location.origin + '/';
    var close = workdir + 'static/images/background/select_menu.png'
    var open = workdir + 'static/images/background/select_menu_close.png'
    
    var navMenu = document.getElementById('navMenu')

    var image = document.getElementById("myImage");
    var availableSrc = image.src
    image.classList.add("hidden");
    setTimeout(function() {
        if (availableSrc === close){
            image.src = open;
            navMenu.style.display = 'flex'
        } else {
            image.src = close;
            navMenu.style.display = 'none'
        }
        image.classList.remove("hidden");
    }, 300)
}
