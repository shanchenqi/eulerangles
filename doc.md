## 欧拉角：

### 分类：

#### 按照旋转次序：

**Proper  Euler angles** (*z-x-z, x-y-x, y-z-y, z-y-z, x-z-x, y-x-y*)

**Tait–Bryan angles** (*x-y-z, y-z-x, z-x-y, x-z-y, z-y-x, y-x-z*)

#### 按轴是否固定：

内旋(intrinsic rotations) = 旋转轴(rotated axis)

外旋(extrinsic rotations) = 固定轴(static/fixed axis)

对一次旋转，绕X轴旋转$\alpha$，绕Y轴旋转$\beta$，绕Z轴旋转$\gamma$，若采用内旋：旋转矩阵$R =X(\alpha) Y(\beta) Z(\gamma) $

若采用外旋，旋转矩阵$R =Z_{\gamma} Y_{\beta} X_{\alpha}$

其中，$X_\alpha={\begin{bmatrix}1&0&0\\0&\cos \alpha &-\sin \alpha \\0&\sin \alpha &\cos \alpha \\\end{bmatrix}}$,$Y_\beta={\begin{bmatrix}1&0&0\\0&\cos \beta &-\sin \beta \\0&\sin \beta &\cos \beta \\\end{bmatrix}}$$,{Z_\alpha=\begin{bmatrix}\cos \gamma &-\sin \gamma &0\\\sin \gamma &\cos \gamma &0\\0&0&1\\\end{bmatrix}}$

### 约定：

1.右手坐标系

2.主动旋转

3.角度的范围： 

**Tait–Bryan angles**   :

$\alpha$(−*π*, *π*].  

$\beta$ [−*π*/2, *π*/2],  

 $\gamma$(−*π*, *π*]. 

说明：$\beta$范围 [−*π*/2, *π*/2]：由于欧拉角存在$X_\alpha Y_\beta Z_\gamma =X_{\alpha+\pi} Y_{-\beta+\pi} Z_{\gamma+\pi } $

所以欧拉角到旋转是一个多对一的映射（即不同的欧拉角可以表示同一个旋转方向），为了取到唯一的解，限制$\beta$ [−*π*/2, *π*/2]。在 （−*π*/2, *π*/2），欧拉角的解是惟一的。只有在$\beta=π/2$, 和$\beta=−π/2$,解不唯一，发生了万向节死锁。

**Proper Euler angles**   

$\alpha$(−*π*, *π*].   

$\beta$[0, *π*],   

$gamma$(−*π*, *π*]. 

说明：$\beta$范围 [0, *π*]：由于欧拉角存在$X_\alpha Y_\beta Z_\gamma =X_{\alpha+\pi} Y_{-\beta} Z_{\gamma+\pi } $

为了取到唯一的解，限制$\beta$ [0， *π*]。在 （0, *π*），欧拉角的解是惟一的。只有在$\beta=0$, 和$\beta=π$,解不唯一，发生了万向节死锁。



# 四元数转欧拉角：

## 四元数转到欧拉角（内旋）：

#### 四元数转到旋转矩阵：

$$
\begin{aligned}\mathbf {R} &={\begin{bmatrix}1-2s(q_{j}^{2}+q_{k}^{2})&2s(q_{i}q_{j}-q_{k}q_{r})&2s(q_{i}q_{k}+q_{j}q_{r})\\2s(q_{i}q_{j}+q_{k}q_{r})&1-2s(q_{i}^{2}+q_{k}^{2})&2s(q_{j}q_{k}-q_{i}q_{r})\\2s(q_{i}q_{k}-q_{j}q_{r})&2s(q_{j}q_{k}+q_{i}q_{r})&1-2s(q_{i}^{2}+q_{j}^{2})\end{bmatrix}}\end{aligned}
$$

### XYZ 欧拉角到旋转矩阵：

$$
M =M(X(\theta_1),Y(\theta_2),Z(\theta_3)) = XYZ
$$


$$
X_{1}Y_{2}Z_{3}={\begin{bmatrix}c_{2}c_{3}&-c_{2}s_{3}&s_{2}\\c_{1}s_{3}+c_{3}s_{1}s_{2}&c_{1}c_{3}-s_{1}s_{2}s_{3}&-c_{2}s_{1}\\s_{1}s_{3}-c_{1}c_{3}s_{2}&c_{3}s_{1}+c_{1}s_{2}s_{3}&c_{1}c_{2}\end{bmatrix}}
$$


#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(-m_{23},m_{33})$

$\theta_2$ = $arcsin(m_{13})$

$\theta_3$ = $arctan2(-m_{12},m_{11})$

当$m_{13}=1$时，$\theta_2=\pi/2$出现万向节死锁：

此时旋转矩阵为：
$$
X_{1}Y_{2}Z_{3}={\begin{bmatrix}0&0&1\\c_{1}s_{3}+c_{3}s_{1}&c_{1}c_{3}-s_{1}s_{3}&0\\s_{1}s_{3}-c_{1}c_{3}&c_{3}s_{1}+c_{1}s_{3}&0\end{bmatrix}}
$$
即：
$$
X_{1}Y_{2}Z_{3}={\begin{bmatrix}0&0&1\\sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)&0\\-cos(\theta_1+\theta_3)&sin(\theta_1+\theta_3)&0\end{bmatrix}}
$$


所以：

$\theta_1+\theta_3$ = $arctan2(m_{21},m_{22})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=arctan2(m_{21},m_{22}) \\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

同理，当$m_{13}=-1$时，$\theta_2=-\pi/2$出现万向节死锁

此时旋转矩阵为：
$$
X_{1}Y_{2}Z_{3}={\begin{bmatrix}0&0&-1\\c_{1}s_{3}-c_{3}s_{1}&c_{1}c_{3}+s_{1}s_{3}&0\\s_{1}s_{3}+c_{1}c_{3}&c_{3}s_{1}-c_{1}s_{3}&0\end{bmatrix}}
$$
即：
$$
X_{1}Y_{2}Z_{3}={\begin{bmatrix}0&0&-1\\-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)&0\\cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)&0\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(m_{32},m_{22})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=arctan2(m_{32},m_{22}) \\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$



### XZY 欧拉角到旋转矩阵：


$$
M =M(X(\theta_1),Z(\theta_2),Y(\theta_3)) = XZY
$$

### 

$$
X_{1}Z_{2}Y_{3}={\begin{bmatrix}c_{2}c_{3}&-s_{2}&c_{2}s_{3}\\s_{1}s_{3}+c_{1}c_{3}s_{2}&c_{1}c_{2}&c_{1}s_{2}s_{3}-c_{3}s_{1}\\c_{3}s_{1}s_{2}-c_{1}s_{3}&c_{2}s_{1}&c_{1}c_{3}+s_{1}s_{2}s_{3}\end{bmatrix}}
$$

#### 可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{32},m_{22})$

$\theta_2$ = $-arcsin(m_{12})$

$\theta_3$ = $arctan2(m_{13},m_{11})$

当$m_{12}=1$时，$\theta_2=-\pi/2$ ，此时旋转矩阵为：
$$
X_{1}Z_{2}Y_{3}={\begin{bmatrix}0&1&0\\s_{1}s_{3}-c_{1}c_{3}&0&-c_{1}s_{3}-c_{3}s_{1}\\-c_{3}s_{1}-c_{1}s_{3}&0&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Z_{2}Y_{3}={\begin{bmatrix}0&1&0\\-cos(\theta_1+\theta_3)&0&-sin(\theta_1+\theta_3)\\-sin(\theta_1+\theta_3)&0&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(-m_{23},m_{33})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(-m_{23},m_{33})\\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$

当$m_{12}=-1$时，$\theta_2=\pi/2$ ，此时旋转矩阵为：
$$
X_{1}Z_{2}Y_{3}=
{\begin{bmatrix}
0&-1&0\\
s_{1}s_{3}+c_{1}c_{3}&0&c_{1}s_{3}-c_{3}s_{1}\\
c_{3}s_{1}-c_{1}s_{3}&0&c_{1}c_{3}+s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Z_{2}Y_{3}=
{\begin{bmatrix}
0&-1&0\\
cos(\theta_1-\theta_3)&0&-sin(\theta_1-\theta_3)\\
sin(\theta_1-\theta_3)&0&cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3= $$arctan(m_{31},m_{33})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan(m_{31},m_{33})\\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

### XYX 欧拉角到旋转矩阵：


$$
M =M(X(\theta_1),Y(\theta_2),X(\theta_3)) = XYX
$$
旋转矩阵：
$$
X_{1}Y_{2}X_{3}={\begin{bmatrix}c_{2}&s_{2}s_{3}&c_{3}s_{2}\\s_{1}s_{2}&c_{1}c_{3}-c_{2}s_{1}s_{3}&-c_{1}s_{3}-c_{2}c_{3}s_{1}\\-c_{1}s_{2}&c_{3}s_{1}+c_{1}c_{2}s_{3}&c_{1}c_{2}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{21},-m_{31})$

$\theta_2$ = $arccos(m_{11})$

$\theta_3$ = $arctan2(m_{12},m_{13})$

当$m_{11}=1$，$\theta_2=0$,旋转矩阵为：
$$
X_{1}Y_{2}X_{3}=
{\begin{bmatrix}
1&0&0\\
0&c_{1}c_{3}-s_{1}s_{3}&-c_{1}s_{3}-c_{3}s_{1}\\
0&c_{3}s_{1}+c_{1}s_{3}&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Y_{2}X_{3}=
{\begin{bmatrix}
1&0&0\\
0&cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)\\
0&sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{32},m_{33})$

$\theta_2=0$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{32},m_{33})\\
   \theta_2=0\\
   \theta_3=0
  \end{cases}$

当$m_{11}=-1$，$\theta_2=\pi$,旋转矩阵为：
$$
X_{1}Y_{2}X_{3}=
{\begin{bmatrix}
-1&0&0\\
0&c_{1}c_{3}+s_{1}s_{3}&-c_{1}s_{3}+c_{3}s_{1}\\
0&c_{3}s_{1}-c_{1}s_{3}&-c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Y_{2}X_{3}=
{\begin{bmatrix}
-1&0&0\\
0&cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)\\
0&sin(\theta_1-\theta_3)&-cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{23},m_{22})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{23},m_{22})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$



### XZX 欧拉角到旋转矩阵：

$$
M =M(X(\theta_1),Z(\theta_2),X(\theta_3)) = XZX
$$


$$
X_{1}Z_{2}X_{3}={\begin{bmatrix}c_{2}&-c_{3}s_{2}&s_{2}s_{3}\\c_{1}s_{2}&c_{1}c_{2}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}c_{2}s_{3}\\s_{1}s_{2}&c_{1}s_{3}+c_{2}c_{3}s_{1}&c_{1}c_{3}-c_{2}s_{1}s_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{31},m_{21})$

$\theta_2$ = $arccos(m_{11})$

$\theta_3$ = $arctan2(m_{13},-m_{12})$

当$m_{11}=1$，$\theta_2=0$,旋转矩阵为：
$$
X_{1}Z_{2}X_{3}=
{\begin{bmatrix}1&0&0\\
0&c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}s_{3}\\
0&c_{1}s_{3}+c_{3}s_{1}&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Z_{2}X_{3}=
{\begin{bmatrix}1&0&0\\
0&cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)\\
0&sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{32},m_{33})$

$\theta_2=0$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{32},m_{33})\\
   \theta_2=0\\
   \theta_3=0
  \end{cases}$

当$m_{11}=-1$，$\theta_2=\pi$,旋转矩阵为：
$$
X_{1}Z_{2}X_{3}=
{\begin{bmatrix}-1&0&0\\
0&-c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}+c_{1}s_{3}\\
0&c_{1}s_{3}-c_{3}s_{1}&c_{1}c_{3}+s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
X_{1}Z_{2}X_{3}=
{\begin{bmatrix}-1&0&0\\
0&-cos(\theta_1-\theta_3)&-sin(\theta_1-\theta_3)\\
0&-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(-m_{32},m_{33})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(-m_{32},m_{33})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$



### 	YXZ 欧拉角到旋转矩阵：

$$
M =M(Y(\theta_1),X(\theta_2),Z(\theta_3)) = YXZ
$$


$$
Y_{1}X_{2}Z_{3}=
{\begin{bmatrix}c_{1}c_{3}+s_{1}s_{2}s_{3}&c_{3}s_{1}s_{2}-c_{1}s_{3}&c_{2}s_{1}\\c_{2}s_{3}&c_{2}c_{3}&-s_{2}\\c_{1}s_{2}s_{3}-c_{3}s_{1}&c_{1}c_{3}s_{2}+s_{1}s_{3}&c_{1}c_{2}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{31},m_{33})$

$\theta_2$ =$arcsin(-m_{23})$

$\theta_3$ = $arctan2(m_{21},m_{22})$

当$m_{23}=1$，$\theta_2=-\pi/2$,旋转矩阵为：
$$
Y_{1}X_{2}Z_{3}=
{\begin{bmatrix}c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}s_{3}&0\\
0&0&1\\
-c_{1}s_{3}-c_{3}s_{1}&-c_{1}c_{3}+s_{1}s_{3}&0\end{bmatrix}}
$$
即：
$$
Y_{1}X_{2}Z_{3}=
{\begin{bmatrix}cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)&0\\
0&0&1\\
-sin(\theta_1+\theta_3)&-cos(\theta_1+\theta_3)&0\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(-m_{12},m_{11})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(-m_{12},m_{11})\\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$

当$m_{23}=-1$，$\theta_2=\pi/2$,旋转矩阵为：
$$
Y_{1}X_{2}Z_{3}=
{\begin{bmatrix}c_{1}c_{3}+s_{1}s_{3}&c_{3}s_{1}-c_{1}s_{3}&0\\
0&0&-1\\
c_{1}s_{3}-c_{3}s_{1}&c_{1}c_{3}+s_{1}s_{3}&0\end{bmatrix}}
$$
即：
$$
Y_{1}X_{2}Z_{3}=
{\begin{bmatrix}cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)&0\\
0&0&-1\\
-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)&0\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$= $arctan2(m_{12},m_{11})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{12},m_{11})\\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

### YZX 欧拉角到旋转矩阵：

$$
M =M(Y(\theta_1),Z(\theta_2),X(\theta_3)) = YZX
$$


$$
Y_{1}Z_{2}X_{3}={\begin{bmatrix}c_{1}c_{2}&s_{1}s_{3}-c_{1}c_{3}s_{2}&c_{3}s_{1}+c_{1}s_{2}s_{3}\\s_{2}&c_{2}c_{3}&-c_{2}s_{3}\\-c_{2}s_{1}&c_{1}s_{3}+c_{3}s_{1}s_{2}&c_{1}c_{3}-s_{1}s_{2}s_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(-m_{31},m_{11})$

$\theta_2$ = $arcsin(m_{21})$

$\theta_3$ = $arctan2(-m_{23},m_{22})$

当$m_{21}=1$，$\theta_2=\pi/2$,旋转矩阵为：
$$
Y_{1}Z_{2}X_{3}={\begin{bmatrix}0&s_{1}s_{3}-c_{1}c_{3}&c_{3}s_{1}+c_{1}s_{3}\\
1&0&0\\
0&c_{1}s_{3}+c_{3}s_{1}&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}Z_{2}X_{3}={\begin{bmatrix}0&-cos(\theta_1+\theta_3)&sin(\theta_1+\theta_3)\\
1&0&0\\
0&sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$= $arctan2(m_{13},m_{33})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{13},m_{33})\\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

当$m_{21}=-1$，$\theta_2=-\pi/2$,旋转矩阵为：
$$
Y_{1}Z_{2}X_{3}={\begin{bmatrix}0&s_{1}s_{3}+c_{1}c_{3}&c_{3}s_{1}-c_{1}s_{3}\\
-1&0&0\\
0&c_{1}s_{3}-c_{3}s_{1}&c_{1}c_{3}+s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}Z_{2}X_{3}={\begin{bmatrix}0&cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)\\
-1&0&0\\
0&-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(m_{13},m_{12})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{13},m_{12})\\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$

### YXY 欧拉角到旋转矩阵：

$$
M =M(Y(\theta_1),X(\theta_2),Y(\theta_3)) = YXY
$$

$$
Y_{1}X_{2}Y_{3}={\begin{bmatrix}c_{1}c_{3}-c_{2}s_{1}s_{3}&s_{1}s_{2}&c_{1}s_{3}+c_{2}c_{3}s_{1}\\s_{2}s_{3}&c_{2}&-c_{3}s_{2}\\-c_{3}s_{1}-c_{1}c_{2}s_{3}&c_{1}s_{2}&c_{1}c_{2}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{12},m_{32})$

$\theta_2$ = $arccos(m_{22})$

$\theta_3$ = $arctan2(m_{21},-m_{23})$

当$m_{22}=1$，$\theta_2=0$,旋转矩阵为：
$$
Y_{1}X_{2}Y_{3}={\begin{bmatrix}
c_{1}c_{3}-s_{1}s_{3}&0&c_{1}s_{3}+c_{3}s_{1}\\
0&1&0\\
-c_{3}s_{1}-c_{1}s_{3}&0&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}X_{2}Y_{3}={\begin{bmatrix}
cos(\theta_1+\theta_3)&0&sin(\theta_1+\theta_3)\\
0&1&0\\
-sin(\theta_1+\theta_3)&0&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3= $$$arctan2(m_{13},m_{11})$$

$\theta_2$=0

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{13},m_{11})\\
   \theta_2=0\\
   \theta_3=0
  \end{cases}$

当$m_{22}=-1$，$\theta_2=\pi$,旋转矩阵为：
$$
Y_{1}X_{2}Y_{3}={\begin{bmatrix}
c_{1}c_{3}+s_{1}s_{3}&0&c_{1}s_{3}-c_{3}s_{1}\\
0&-1&0\\
-c_{3}s_{1}+c_{1}s_{3}&0&-c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}X_{2}Y_{3}={\begin{bmatrix}
cos(\theta_1-\theta_3)&0&-sin(\theta_1-\theta_3)\\
0&-1&0\\
-sin(\theta_1-\theta_3)&0&-cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3 =arctan2(-m_{31},m_{11})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(-m_{31},m_{11})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$

### YZY 欧拉角到旋转矩阵：

$$
M =M(Y(\theta_1),Z(\theta_2),Y(\theta_3)) = YZY
$$


$$
Y_{1}Z_{2}Y_{3}={\begin{bmatrix}c_{1}c_{2}c_{3}-s_{1}s_{3}&-c_{1}s_{2}&c_{3}s_{1}+c_{1}c_{2}s_{3}\\c_{3}s_{2}&c_{2}&s_{2}s_{3}\\-c_{1}s_{3}-c_{2}c_{3}s_{1}&s_{1}s_{2}&c_{1}c_{3}-c_{2}s_{1}s_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{32},-m_{12})$

$\theta_2$ = $arccos(m_{22})$

$\theta_3$ = $arctan2(m_{23},m_{21})$

当$m_{22}=1$，$\theta_2=0$,旋转矩阵为：
$$
Y_{1}Z_{2}Y_{3}={\begin{bmatrix}
c_{1}c_{3}-s_{1}s_{3}&0&c_{3}s_{1}+c_{1}s_{3}\\
0&1&0\\
-c_{1}s_{3}-c_{3}s_{1}&0&c_{1}c_{3}-s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}Z_{2}Y_{3}={\begin{bmatrix}
cos(\theta_1+\theta_3)&0&sin(\theta_1+\theta_3)\\
0&1&0\\
-sin(\theta_1+\theta_3)&0&cos(\theta_1+\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{13},m_{11})$

$\theta_2=0$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{13},m_{11})\\
   \theta_2=0\\
   \theta_3=0
  \end{cases}$

当$m_{22}=-1$，$\theta_2=\pi$,旋转矩阵为：
$$
Y_{1}Z_{2}Y_{3}={\begin{bmatrix}
-c_{1}c_{3}-s_{1}s_{3}&0&c_{3}s_{1}-c_{1}s_{3}\\
0&-1&0\\
-c_{1}s_{3}+c_{3}s_{1}&0&c_{1}c_{3}+s_{1}s_{3}\end{bmatrix}}
$$
即：
$$
Y_{1}Z_{2}Y_{3}={\begin{bmatrix}
-cos(\theta_1-\theta_3)&0&sin(\theta_1-\theta_3)\\
0&-1&0\\
sin(\theta_1-\theta_3)&0&cos(\theta_1-\theta_3)\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(m_{13},m_{13})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{13},m_{11})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$

### ZXY 欧拉角到旋转矩阵：

$$
Z_{1}X_{2}Y_{3}={\begin{bmatrix}c_{1}c_{3}-s_{1}s_{2}s_{3}&-c_{2}s_{1}&c_{1}s_{3}+c_{3}s_{1}s_{2}\\c_{3}s_{1}+c_{1}s_{2}s_{3}&c_{1}c_{2}&s_{1}s_{3}-c_{1}c_{3}s_{2}\\-c_{2}s_{3}&s_{2}&c_{2}c_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(-m_{12},m_{22})$

$\theta_2$ = $arcsin(m_{32})$

$\theta_3$ = $arctan2(-m_{31},m_{33})$

当$m_{32}=1$，$\theta_2=\pi/2$,旋转矩阵为：
$$
Z_{1}X_{2}Y_{3}={\begin{bmatrix}
c_{1}c_{3}-s_{1}s_{3}&0&c_{1}s_{3}+c_{3}s_{1}\\
c_{3}s_{1}+c_{1}s_{3}&0&s_{1}s_{3}-c_{1}c_{3}\\
0&1&0\end{bmatrix}}
$$
即：
$$
Z_{1}X_{2}Y_{3}={\begin{bmatrix}
cos(\theta_1+\theta_3)&0&sin(\theta_1+\theta_3)\\
sin(\theta_1+\theta_3)&0&-cos(\theta_1+\theta_3)\\
0&1&0\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{21},m_{11})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{21},m_{11})\\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

当$m_{32}=-1$，$\theta_2=-\pi/2$,旋转矩阵为
$$
Z_{1}X_{2}Y_{3}={\begin{bmatrix}
c_{1}c_{3}+s_{1}s_{3}&0&c_{1}s_{3}-c_{3}s_{1}\\
c_{3}s_{1}-c_{1}s_{3}&0&s_{1}s_{3}+c_{1}c_{3}\\
0&-1&0\end{bmatrix}}
$$
即：
$$
Z_{1}X_{2}Y_{3}={\begin{bmatrix}
cos(\theta_1-\theta_3)&0&-sin(\theta_1-\theta_3)\\
sin(\theta_1-\theta_3)&0&cos(\theta_1-\theta_3)\\
0&-1&0\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(m_{21},m_{11})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{21},m_{11})\\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$

### ZYX 欧拉角到旋转矩阵：

$$
Z_{1}Y_{2}X_{3}={\begin{bmatrix}c_{1}c_{2}&c_{1}s_{2}s_{3}-c_{3}s_{1}&s_{1}s_{3}+c_{1}c_{3}s_{2}\\c_{2}s_{1}&c_{1}c_{3}+s_{1}s_{2}s_{3}&c_{3}s_{1}s_{2}-c_{1}s_{3}\\-s_{2}&c_{2}s_{3}&c_{2}c_{3}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{21},m_{11})$

$\theta_2$ = $arcsin(-m_{31})$

$\theta_3$ = $arctan2(m_{32},m_{33})$

当$m_{31}=1$，$\theta_2=-\pi/2$,旋转矩阵为
$$
Z_{1}Y_{2}X_{3}={
\begin{bmatrix}0&-c_{1}s_{3}-c_{3}s_{1}&s_{1}s_{3}-c_{1}c_{3}\\
0&c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}s_{3}\\
1&0&0\end{bmatrix}}
$$
即：
$$
Z_{1}Y_{2}X_{3}={
\begin{bmatrix}0&-sin(\theta_1+\theta_3)&-cos(\theta_1+\theta_3)\\
0&cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)\\
1&0&0\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(-m_{12},m_{22})$

$\theta_2=-\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(-m_{12},m_{22})\\
   \theta_2=-\pi/2\\
   \theta_3=0
  \end{cases}$

当$m_{31}=-1$，$\theta_2=\pi/2$,旋转矩阵为
$$
Z_{1}Y_{2}X_{3}={
\begin{bmatrix}0&c_{1}s_{3}-c_{3}s_{1}&s_{1}s_{3}+c_{1}c_{3}\\
0&c_{1}c_{3}+s_{1}s_{3}&c_{3}s_{1}-c_{1}s_{3}\\
-1&0&0\end{bmatrix}}
$$
即：
$$
Z_{1}Y_{2}X_{3}={
\begin{bmatrix}0&-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)\\
0&cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)\\
-1&0&0\end{bmatrix}}
$$


所以：

$\theta_1-\theta_3$ = $arctan2(m_{23},m_{22})$

$\theta_2=\pi/2$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{23},m_{22})\\
   \theta_2=\pi/2\\
   \theta_3=0
  \end{cases}$

### ZXZ 欧拉角到旋转矩阵：

$$
Z_{1}X_{2}Z_{3}={\begin{bmatrix}c_{1}c_{3}-c_{2}s_{1}s_{3}&-c_{1}s_{3}-c_{2}c_{3}s_{1}&s_{1}s_{2}\\c_{3}s_{1}+c_{1}c_{2}s_{3}&c_{1}c_{2}c_{3}-s_{1}s_{3}&-c_{1}s_{2}\\s_{2}s_{3}&c_{3}s_{2}&c_{2}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(-m_{13},m_{23})$

$\theta_2$ = $arccos(m_{33})$

$\theta_3$ = $arctan2(m_{31},m_{32})$

当$m_{33}=1$，$\theta_2=0$,旋转矩阵为
$$
Z_{1}X_{2}Z_{3}={\begin{bmatrix}
c_{1}c_{3}-s_{1}s_{3}&-c_{1}s_{3}-c_{3}s_{1}&0\\
c_{3}s_{1}+c_{1}s_{3}&c_{1}c_{3}-s_{1}s_{3}&0\\
0&0&1\end{bmatrix}}
$$
即：
$$
Z_{1}X_{2}Z_{3}={\begin{bmatrix}
cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)&0\\
sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)&0\\
0&0&1\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{21},m_{22})$

$\theta_2=0$

$\theta_3=0$

当$m_{33}=-1$，$\theta_2=\pi$,旋转矩阵为
$$
Z_{1}X_{2}Z_{3}={\begin{bmatrix}
c_{1}c_{3}+s_{1}s_{3}&-c_{1}s_{3}+c_{3}s_{1}&0\\
c_{3}s_{1}-c_{1}s_{3}&-c_{1}c_{3}-s_{1}s_{3}&0\\
0&0&-1\end{bmatrix}}
$$
即：
$$
Z_{1}X_{2}Z_{3}={\begin{bmatrix}
cos(\theta_1-\theta_3)&sin(\theta_1-\theta_3)&0\\
sin(\theta_1-\theta_3)&-cos(\theta_1-\theta_3)&0\\
0&0&-1\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan2(m_{21},m_{11})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{21},m_{11})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$

### ZYZ 欧拉角到旋转矩阵：

$$
Z_{1}Y_{2}Z_{3}={\begin{bmatrix}c_{1}c_{2}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}c_{2}s_{3}&c_{1}s_{2}\\c_{1}s_{3}+c_{2}c_{3}s_{1}&c_{1}c_{3}-c_{2}s_{1}s_{3}&s_{1}s_{2}\\-c_{3}s_{2}&s_{2}s_{3}&c_{2}\end{bmatrix}}
$$

#### 此时可以求解 $\theta_1$ ,$\theta_2$,$\theta_3$ :

$\theta_1$ = $arctan2(m_{23},m_{13})$

$\theta_2$ = $arccos(m_{33})$

$\theta_3$ = $arctan2(m_{32},-m_{31})$

当$m_{33}=1$，$\theta_2=0$,旋转矩阵为
$$
Z_{1}Y_{2}Z_{3}={\begin{bmatrix}
c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}-c_{1}s_{3}&0\\
c_{1}s_{3}+c_{3}s_{1}&c_{1}c_{3}-s_{1}s_{3}&0\\
0&0&1\end{bmatrix}}
$$
即：
$$
Z_{1}Y_{2}Z_{3}={\begin{bmatrix}
cos(\theta_1+\theta_3)&-sin(\theta_1+\theta_3)&0\\
sin(\theta_1+\theta_3)&cos(\theta_1+\theta_3)&0\\
0&0&1\end{bmatrix}}
$$
所以：

$\theta_1+\theta_3$ = $arctan2(m_{21},m_{11})$

$\theta_2=0$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{21},m_{11})\\
   \theta_2=0\\
   \theta_3=0
  \end{cases}$

当$m_{33}=-1$，$\theta_2=\pi$,旋转矩阵为
$$
Z_{1}Y_{2}Z_{3}={\begin{bmatrix}
-c_{1}c_{3}-s_{1}s_{3}&-c_{3}s_{1}+c_{1}s_{3}&0\\
c_{1}s_{3}-c_{3}s_{1}&c_{1}c_{3}+s_{1}s_{3}&0\\
0&0&-1\end{bmatrix}}
$$
即：
$$
Z_{1}Y_{2}Z_{3}={\begin{bmatrix}
-cos(\theta_1-\theta_3)&-sin(\theta_1-\theta_3)&0\\
-sin(\theta_1-\theta_3)&cos(\theta_1-\theta_3)&0\\
0&0&-1\end{bmatrix}}
$$
所以：

$\theta_1-\theta_3$ = $arctan(m_{21},m_{11})$

$\theta_2=\pi$

为了减少旋转次数，我们取$\theta_3=0$，可以得到一组解：$\begin{cases}
   \theta_1=\arctan2(m_{21},m_{11})\\
   \theta_2=\pi\\
   \theta_3=0
  \end{cases}$