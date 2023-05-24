function changeImage() {
    let close = 'static/images/background/select_menu.png';
    let open = 'static/images/background/select_menu_close.png';
    
    let navMenu = document.getElementById('navMenu')
    let image = document.getElementById("myImage");
    let availableSrc = 'static/' + image.src.split('static/')[1]

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

let rotateDeg = 180
function changeSelector() {
    let selector = document.getElementById('selector_city');
    arrows = [
        document.getElementById('arrow1').style, 
        document.getElementById('arrow2').style
    ]
    
    if (rotateDeg === 0){
        rotateDeg = 180
        selector.style.display = 'none'
    }else{
        rotateDeg = 0
        selector.style.display = 'flex'
    }
    arrows.forEach(arrow => {
        arrow.transform = 'rotate(' + rotateDeg + 'deg)';
    });
}