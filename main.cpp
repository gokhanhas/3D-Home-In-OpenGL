//
//  main.cpp
//
//  Created by Gökhan HAS on 13.05.2021.
//  161044067
//

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <OpenGL/OpenGL.h>
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;
 
// -----------------------------------------------
// Rotate, Scale ve Translate işlemleri
// için gerekli değişkenlerin float tipinde tanımlanması.
GLfloat x_rotate = 0.0f;
GLfloat y_rotate = 0.0f;
GLfloat z_rotate = 0.0f;

GLfloat x_scale = 1.0f;
GLfloat y_scale = 1.0f;
GLfloat z_scale = 1.0f;

GLfloat x_translate = 0.0f;
GLfloat y_translate = 0.0f;
GLfloat z_translate = 0.0f;
// -----------------------------------------------

// Function defines ...
void keyboardActions(unsigned char k, int , int);
void resize(int w, int h);
void draw3DHouse();

// -----------------------------------------------


int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    
    // Pencere boyutu oluşturulur ...
    glutInitWindowSize(1620, 720);
    
    // Pencere oluşturulur ve aşağıdaki yazı yazılır.
    glutCreateWindow("Computer Graphics - Gökhan Has * 161044067");
    glEnable(GL_DEPTH_TEST);
    
    // Ekrana çizilecek olan fonksiyon, parametre olarak alınır.
    glutDisplayFunc(draw3DHouse);
    
    // Klavyede tuşlara basıldığında oluşacak aksiyonların bulunduğu fonksiyon parametre olarak gönderirir.
    glutKeyboardFunc(keyboardActions);
    
    // Pencere boyutu değiştiğinde veya güncellendiğinde aksiyonların bulunduğu fonksiyon parametre olarak gönderilir.
    glutReshapeFunc(resize);
    
    // Sonsuz döngüde uygulamanın çalışılması sağlanır.
    glutMainLoop();
    
    return 0;
}



// Klavyede tuşlara basıldığında hangi aksiyonun meydana getireceği değişkenlerin değerlerin değişimi ve ardından tekrar çizilmesini sağlayan fonksiyondur. KÜÇÜK KARAKTERLERE GÖRE YAZILMIŞTIR. CAPS LOCK AÇIK OLDUĞUNDA AYNI KARAKTERLER BASILDIĞINDA İŞLEMEZ, UYGULANMAZ !!!
void keyboardActions(unsigned char k, int , int) {
    switch (k) {
        case 'w':
            x_rotate -= 1.0;
            break;
        case 'a':
            y_rotate -= 1.0;
            break;
        case 's':
            x_rotate += 1.0;
            break;
        case 'd':
            y_rotate += 1.0;
            break;
        case 'q':
            z_rotate += 1.0;
            break;
        case 'e':
            z_rotate -= 1.0;
            break;
        case 'z':
            x_translate += 0.1f;
            break;
        case 'x':
            x_translate -= 0.1f;
            break;
        case 'c':
            y_translate += 0.1f;
            break;
        case 'v':
            y_translate -= 0.1f;
            break;
        case 'b':
            z_translate += 0.1f;
            break;
        case 'n':
            z_translate -= 0.1f;
            break;
        case 'f':
            x_scale += 0.1;
            y_scale += 0.1;
            z_scale += 0.1;
            break;
        case 'g':
            x_scale -= 0.1;
            y_scale -= 0.1;
            z_scale -= 0.1;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
    
    // İlgili değerler güncellendikten sonra tekrardan çizimlerin güncellenmesi için aşağıdaki fonksiyon çağrılır.
    glutPostRedisplay();
}


void resize(int width, int height) {
    // İlk iki parametresi x ve y dir. Bu koordinatları pencere cinsinden with ve height'a göre dönüştürür. Görüntü alanı genişliği ve yüksekliği, uygulamaya bağlı olan bir aralığa sabitlenir.
    glViewport(0, 0, width, height);
    
    // Sonraki matris işlemlerini projeksiyon matrisi yığınına uygular.
    glMatrixMode(GL_PROJECTION);
    
    // Özdeşlik matrisini, varsayılan durumuna geri döndürür. Başlangıç ​​noktasından yeniden başlamak istenildiğinde kullanılır.
    glLoadIdentity();
    
    // Kullanıcının evi nasıl görmesini ayarlayan fonksiyondur. Yeniden yükleme işlemi yapıldığında aynı oranda kullanıcının görmesini sağlar. Örneğin ilk parametresi 90 olsaydı ev daha uzakta olacaktı. İkinci parametre orandır. Son iki parametre ise z ekseninde yakınlaştırma, uzaklaştırma ve yakınlaştırıp uzaklaştığında görüntünün terse doğru gitmesi ile ilgilidir.
    gluPerspective(60.0, (double) width / (double) height, 1.0, 100.0);
}

void draw3DHouse() {
    // Her çizimden sonra glClear fonksiyonu çağrılmaz ise ekran simsiyah veya renklerin arasında siyah kısımlarla kalmaktadır. Önceki pikseller temizlenmelidir.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Sonraki matris işlemlerini modelview matris yığınına uygular.
    glMatrixMode(GL_MODELVIEW);
    
    // Özdeşlik matrisini, varsayılan durumuna geri döndürür. Başlangıç ​​noktasından yeniden başlamak istenildiğinde kullanılır.
    glLoadIdentity();
    
    // Evin pencerede ortalarda gözükmesi için sahip olması gereken eksen değerleridir.
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25f, -1.0f, -3.5f);
    
    // Translate işlemi için hangi değişkenlerin kullanılacağı sırasıyla verilir.
    glTranslatef(x_translate, y_translate,z_translate);
    
    // Rotate değişkenleri ve hangi eksende rotate işleminin yapılacağını belirtme.
    glRotatef(x_rotate, 1.0f, 0.0f, 0.0f);
    glRotatef(y_rotate, 0.0f, 1.0f, 0.0f);
    glRotatef(z_rotate, 0.0f, 0.0f, 1.0f);
    
    // Scale işlemi için hangi değişkenlerin kullanılacağı sırasıyla verilir.
    glScalef(x_scale, y_scale, z_scale);
    

    /* Evin ön tarafı dikdörtgen şeklinde */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.537, 0.901, 0.890);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(1.0, 0.1, 0.0);
    glVertex3f(1.0, 1.5, 0.0);
    glVertex3f(0.1, 1.5, 0.0);
    glEnd();
    
    
    /* Evin arka tarafı dikdörtgen şeklinde */
    glColor3f(0.537, 0.901, 0.890);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, 0.1, 0.5);
    glVertex3f(1, 0.1, 0.5);
    glVertex3f(1, 1.5, 0.5);
    glVertex3f(0.1, 1.5, 0.5);
    glEnd();

    /* Evin sağ tarafı, dikdörtgen şeklinde */
    glColor3f(0.1, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.1, 0.1, 0.5);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.1, 1.5, 0.0);
    glVertex3f(0.1, 1.5, 0.5);
    glEnd();

    /* Evin sol tarafı dikdötgen şeklinde */
    glColor3f (0.1, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.0);
    glVertex3f (1, 1.5, 0.0);
    glVertex3f (1, 1.5, 0.5);
    glEnd();

    /* Sol taraftaki dikdörtgenin üstündeki üçgen çatı */
    glColor3f (1.0, 0.2, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex3f (1, 1.5, 0.0);
    glVertex3f (1, 1.5, 0.5);
    glVertex3f (1, 1.8, 0.25);
    glEnd();

    /* Sağ taraftaki dikdörtgenin üstündeki üçgen çatı  */
    glColor3f (1.0, 0.2, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.1, 1.5, 0.0);
    glVertex3f (0.1, 1.5, 0.5);
    glVertex3f (0.1, 1.8, 0.25);
    glEnd();

    /* Ön taraftakı kırmızı çatı */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 1.5, 0.0);
    glVertex3f (1, 1.5, 0.0);
    glVertex3f (1, 1.8, 0.25);
    glVertex3f (0.1, 1.8, 0.25);
    glEnd();

    /* Arka Taraftaki kırmızı çatı */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.1, 1.5, 0.5);
    glVertex3f (1, 1.5, 0.5);
    glVertex3f (1, 1.8, 0.25);
    glVertex3f (0.1, 1.8, 0.25);
    glEnd();

    /* Kapı  */
    glColor3f (0.247, 0.031, 0.788);
    glBegin(GL_POLYGON);
    glVertex3f (1.001, 0.1, 0.18);
    glVertex3f (1.001, 0.1, 0.32);
    glVertex3f (1.001, 0.40, 0.32);
    glVertex3f (1.001, 0.40, 0.18);
    glEnd();
    
    
    /* Kapının üstündeki ilk pencere  */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (1.001, 0.7, 0.18);
    glVertex3f (1.001, 0.7, 0.32);
    glVertex3f (1.001, 0.87, 0.32);
    glVertex3f (1.001, 0.87, 0.18);
    glEnd();
    
    /* Kapının üstündeki ikinci pencere */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (1.001, 1.07, 0.18);
    glVertex3f (1.001, 1.07, 0.32);
    glVertex3f (1.001, 1.24, 0.32);
    glVertex3f (1.001, 1.24, 0.18);
    glEnd();
    
    
    /* Kapının arka tarafındaki ilk pencere */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.09, 0.7, 0.18);
    glVertex3f (0.09, 0.7, 0.32);
    glVertex3f (0.09, 0.87, 0.32);
    glVertex3f (0.09, 0.87, 0.18);
    glEnd();
    
    /* Kapının arka tarafındaki ikinci (ortanca) pencere */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.09, 1.07, 0.18);
    glVertex3f (0.09, 1.07, 0.32);
    glVertex3f (0.09, 1.24, 0.32);
    glVertex3f (0.09, 1.24, 0.18);
    glEnd();
    
    /* Kapının arka tarafındaki üçüncü (en üstteki) pencere */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.09, 0.33, 0.18);
    glVertex3f (0.09, 0.33, 0.32);
    glVertex3f (0.09, 0.5, 0.32);
    glVertex3f (0.09, 0.5, 0.18);
    glEnd();
    
    
    // ------------------------------------------------
    // ÖN VE ARKA TARAFTAKİ PENCERELER
    // ------------------------------------------------

    /* Arka Pencere 1 */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.35, 0.33, -0.0005);
    glVertex3f(0.5, 0.33, -0.0005);
    glVertex3f(0.5, 0.5, -0.0005);
    glVertex3f(0.35, 0.5, -0.0005);
    glEnd();

    /* Arka Pencere 2 */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.6, 0.33, -0.0005);
    glVertex3f(0.75, 0.33, -0.0005);
    glVertex3f(0.75, 0.5, -0.0005);
    glVertex3f(0.6, 0.5, -0.0005);
    glEnd();
    
    /* Arka Pencere 3 */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.35, 0.7, -0.0005);
    glVertex3f(0.5, 0.70, -0.0005);
    glVertex3f(0.5, 0.87, -0.0005);
    glVertex3f(0.35, 0.87, -0.0005);
    glEnd();
    
    /* Arka Pencere 4 */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.6, 0.7, -0.0005);
    glVertex3f(0.75, 0.7, -0.0005);
    glVertex3f(0.75, 0.87, -0.0005);
    glVertex3f(0.6, 0.87, -0.0005);
    glEnd();
    
    /* Arka Pencere 5 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.35, 1.07, -0.0005);
    glVertex3f(0.5, 1.07, -0.0005);
    glVertex3f(0.5, 1.24, -0.0005);
    glVertex3f(0.35, 1.24, -0.0005);
    glEnd();
    
    /* Arka Pencere 6 */
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.6, 1.07, -0.0005);
    glVertex3f(0.75, 1.07, -0.0005);
    glVertex3f(0.75, 1.24, -0.0005);
    glVertex3f(0.6, 1.24, -0.0005);
    glEnd();
    
    /* Ön Pencere 1 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.6, 0.33, 0.5005);
    glVertex3f (0.75, 0.33, 0.5005);
    glVertex3f (0.75, 0.5, 0.5005);
    glVertex3f (0.6, 0.5, 0.5005);
    glEnd();

    /* Ön Pencere 2 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.35, 0.33, 0.5005);
    glVertex3f (0.5, 0.33, 0.5005);
    glVertex3f (0.5, 0.5, 0.5005);
    glVertex3f (0.35, 0.5, 0.5005);
    glEnd();
    
    
    /* Ön Pencere 3 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.35, 0.7, 0.5005);
    glVertex3f (0.5, 0.70, 0.5005);
    glVertex3f (0.5, 0.87, 0.5005);
    glVertex3f (0.35, 0.87, 0.5005);
    glEnd();
    
    /* Ön Pencere 4 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.6, 0.7, 0.5005);
    glVertex3f (0.75, 0.7, 0.5005);
    glVertex3f (0.75, 0.87, 0.5005);
    glVertex3f (0.6, 0.87, 0.5005);
    glEnd();
    
    /* Ön Pencere 5 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.35, 1.07, 0.5005);
    glVertex3f (0.5, 1.07, 0.5005);
    glVertex3f (0.5, 1.24, 0.5005);
    glVertex3f (0.35, 1.24, 0.5005);
    glEnd();
    
    /* Ön Pencere 6 */
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.6, 1.07, 0.5005);
    glVertex3f (0.75, 1.07, 0.5005);
    glVertex3f (0.75, 1.24, 0.5005);
    glVertex3f (0.6, 1.24, 0.5005);
    glEnd();
    
    // ------------------------------------------------
    
    /* Evin altındaki (zemindeki) dikdörtgen şeklindeki yapı */
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.2, 0.5);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.0);
    glEnd();
    
    // Arabelleğin (buffer) hepsini boşaltır ve verilen tüm komutların gerçek işleme motoru tarafından kabul edildiği zamana kadar hızlı yürütülmesine neden olur.
    glFlush ();
    
    // Geçerli matris yığınını bir aşağı iter ve geçerli matrisi çoğaltır. Yani, bir glPushMatrix çağrısından sonra yığının üstündeki matris, altındaki matris ile aynıdır.
    glPopMatrix();
    
    // Bilgisayara geçerli çerçeve ile işin bittiğini bildiren fonksiyondur. Bu çerçevenin görüntülenebilmesi ve bir sonraki üzerinde çalışmaya başlayabilmek için arabelleklerin değiştirilmesi gerekir.
    glutSwapBuffers();
}
