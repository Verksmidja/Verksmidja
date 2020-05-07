## [Rc Car Tinkercad](https://www.tinkercad.com/things/67nPdctYZgX-car/editel?sharecode=fHQJBpK-BEL3owfgGd8jFX-ldt88Felxd8lBaDWrvVY)
### Það sem þarð í þetta
 * 2 servo motors
 * 2 Dc motors
 * ultrasonic distance sensor
 * H-Brige motor dirve
 * 4 takka 
 * viðnám
 * 2 ardurino
 * Lcd Display
 * wírar
### Samsetning
  1. Teingja 5v og Ground við Bread bord
  1. Teingja Servo motorana við power ground og pinna 3
  1. Teinga Power, Ground, og pinna 6, 5 og 4 við H-Brige 
  1. Teingja ultrasonic distance sensor við pinna 8 og 7
  1. Teingja Ground og pinna A4 og A5 við hitt ardurionoið
  1. Teingja Saman Lcd Displayið
  1. Teingja inn 4 takka
![circut](https://github.com/Tardis2105/Verksmidja/blob/master/Rc%20car/Citcut.png)
### Kóðun
1. Bíllinn 
 * setja upp 3 funcions sem strórna hvernig servo motorinn snýr 
 * setja upp funcions sem stjórna áttini á Dc motorinum
 * setja inn funcion sem les Ultrasonic distance sensorinn
 * setja upp IC2 comunication sem Slave
 * Þergar Master Requestar data skilar það value af Ultrasonic distance sensorinn
 * gera það þannig að þegar gögn frá Master er sent þá fara þau í sitt eigið variable
 * Gera helling af If statments sem kveikja á Servo og DC motor Funcions eftir því hvað er valið
 #### [Bíllin Kóði](https://github.com/Tardis2105/Verksmidja/blob/master/Rc%20car/Rc%20Car..ino)
 1. Fjarsteringinn
 * Setja upp IC2 comunication sem Master
 * setja upp Funcion sem requestar fjarlægð að vegg og Skrifar það á Lcd Skjáinn 
 * Setja upp IF statmest sem finur út havða takka var ítt á og merkir við rétt value
 * Senda valuið á Bílinn
 #### [Fjarstering Kóði](https://github.com/Tardis2105/Verksmidja/blob/master/Rc%20car/Controler.ino)
 
 ### Hönnun
 [Tinckercad](https://www.tinkercad.com/things/ctOUQt1nk8s-rc-car/edit?sharecode=ZhOycxg5g-h4x8SwpXJ3j1ZHdYJqIiJnIg_Ib6-h4QI)
