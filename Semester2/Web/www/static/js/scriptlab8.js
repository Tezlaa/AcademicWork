window.onload = ready_message

function calculate() {
    var x_max = parseFloat(document.getElementById('x_max').value);
    var x_min = parseFloat(document.getElementById('x_min').value);
    var z_max = parseFloat(document.getElementById('z_max').value);
    var z_min = parseFloat(document.getElementById('z_min').value);
    var step = parseFloat(document.getElementById('step').value);
    var resultContainer = document.getElementById('result');
    resultContainer.innerHTML = '';

    if (x_max <= 0 || x_min <= 0 || z_max <= 0 || z_min <= 0) {
      alert('Усі числа повинні бути позитивними.');
      return;
    }

    if (x_min >= x_max) {
      alert('Початкове значення x повинно бути менше кінцевого значення.');
      return;
    }

    if (z_min >= z_max) {
      alert('Початкове значення z повинно бути менше кінцевого значення.');
      return;
    }

    if (step > Math.abs(x_max - x_min) || step > Math.abs(z_max - z_min)) {
      alert('Крок не повинен перевищувати різниці між початковим та кінцевим значеннями.');
      return;
    }

    var znach = [];
    var func = [];

    for (var x = x_min; x <= x_max; x += step) {
      znach.push(x);

      for (var z = z_min; z <= z_max; z += step) {
        var result = (Math.cos(z) - 1 / Math.sin(x)) + (Math.sin(2 * z) + (3 / 5 * x)) * (4 * x);
        func.push(result);
      }
    }

    var result = "";

    var resultFormat = document.querySelector('input[name="resultFormat"]:checked').value;
    if (resultFormat === 'newWindow') {
      var newWindow = window.open();
      result += "<h1>Результати:</h1>";
      result += "<p>Значення x: " + znach.join(", ") + "</p>";
      result += "<p>Значення функції: " + func.join(", ") + "</p>";
      newWindow.document.write(result);
      newWindow.document.close();
    } else if (resultFormat === 'samePage') {
      result += "<h1>Результати:</h1>";
      result += "<p>Значення x: " + znach.join(", ") + "</p>";
      result += "<p>Значення функції: " + func.join(", ") + "</p>";
      resultContainer.innerHTML = result;
    } else {
      result += "Значення x: " + znach.join(", ");
      result += "Значення функції: " + func.join(", ");
      alert(result);
    }
}


function ready_message() {
    var nowHour = new Date().getHours();

    if (nowHour >= 7 && nowHour < 12){
        message = "Доброго ранку";
    } else if (nowHour >= 12 && nowHour < 17){
        message = "Доброго дня";
    } else if (nowHour >= 17 && nowHour < 24){
        message = "Доброго вечора";
    } else {
        message = "Доброй ночі";
    }

    document.getElementById('hello_message').innerHTML = message;
}
