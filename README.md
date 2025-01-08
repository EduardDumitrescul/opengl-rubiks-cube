# OpenGL - Rubik's Cube

**Grafica pe calculator - proiect 3d**

*Eduard-Valentin Dumitrescul - grupa 332*

### 1. Conceptul proiectului
Reprezentarea 3d a unui cub rubik interactiv

### 2. Elemente incluse
![alt text](image.png)
- iluminare
- umbra
- ceata
- cuaternioni
![alt text](image-1.png)
- animatii
![alt text](image-2.png)

### 3. Originalitate
Implementarea folosing strict principii de baza ale OpenGL si C++.

### 4. Capturi de ecran
![alt text](image-3.png)
![alt text](image-4.png)
![alt text](image-5.png)

#### Cuaternioni
```
glm::quat deltaRotation = glm::angleAxis(glm::radians(90.0f) * sign, glm::vec3(0.0f, 1.0f, 0.0f));
            glm::quat interpolatedRotation = glm::slerp({1, 0, 0, 0}, deltaRotation, 1.0f * animationProgress / animationDuration);
            cubes[i][j][k]->setAnimationRotation(interpolatedRotation);
```

```
    glm::quat rotation = {1,0 , 0, 0};
    glm::quat animationRotation = {1, 0, 0, 0};
```