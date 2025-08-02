# Guía de Debugging para el Proyecto Yeru

Este proyecto está configurado con un sistema completo de debugging para C++ usando CMake y Zed Editor.

## Configuración del Proyecto

El proyecto utiliza:
- **CMake** para el sistema de build
- **CodeLLDB** como adaptador de debugging
- **Saucer** framework para aplicaciones web nativas
- **C++23** como estándar del lenguaje

## Configuraciones de Build

### Debug Mode
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

### Release Mode
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

## Usando el Debugger en Zed

### Configuraciones Disponibles

#### ✅ Configuraciones Recomendadas (Estables)
1. **Debug App (GDB)** - Configuración más estable
2. **Debug App (GDB - Stop on Entry)** - Se detiene al inicio del programa
3. **Simple Debug (GDB)** - Configuración básica sin build automático

#### ⚠️ Configuraciones Experimentales
4. **Debug App (CodeLLDB)** - Puede fallar con "shutdown unexpectedly"
5. **Debug App (Native LLDB)** - Alternativa nativa
6. **Attach to Process** - Se conecta a un proceso en ejecución

### Cómo Usar

1. **Establecer Breakpoints:**
   - Haz clic en el margen izquierdo del editor junto al número de línea
   - Los breakpoints aparecen como puntos rojos

2. **Iniciar Debugging:**
   - Presiona `Cmd+Shift+P` (Mac) o `Ctrl+Shift+P` (Linux/Windows)
   - Busca "Debug: Start"
   - **Recomendado**: Selecciona "Debug App (GDB)" para evitar errores
   - Si falla, usa el debugging manual: `./test_debug.sh gdb`

3. **Controles de Debugging:**
   - **Continue (F5):** Continuar ejecución
   - **Step Over (F10):** Ejecutar línea actual
   - **Step Into (F11):** Entrar en función
   - **Step Out (Shift+F11):** Salir de función actual
   - **Stop:** Detener debugging

## Tareas Disponibles

Puedes ejecutar estas tareas desde el Command Palette (`Cmd+Shift+P`):

- **Configure (Debug)** - Configura CMake en modo Debug
- **Configure (Release)** - Configura CMake en modo Release
- **Build Debug** - Compila en modo Debug
- **Build Release** - Compila en modo Release
- **Clean** - Limpia archivos de build
- **Run App** - Ejecuta la aplicación
- **Build and Run** - Compila y ejecuta

## Puntos de Debugging Útiles

El archivo `main.cc` incluye varios `std::cout` statements para debugging:

1. **Línea 6:** Inicio de aplicación
2. **Línea 12:** Aplicación inicializada  
3. **Línea 18:** SmartView creado
4. **Línea 21:** Título de ventana establecido
5. **Línea 24:** Dev tools habilitadas
6. **Línea 28-31:** Función `add_ten` llamada y resultado
7. **Línea 34:** Función nativa expuesta
8. **Línea 37:** Archivo HTML establecido
9. **Línea 40:** Ventana mostrada, entrando en loop
10. **Línea 44:** Aplicación saliendo

### Debugging Manual Alternativo
Si Zed falla, usa el script incluido:
```bash
# Iniciar GDB con breakpoint en main
./test_debug.sh gdb
(gdb) break main
(gdb) run
(gdb) next  # Paso a paso
```

## Debugging Tips

### Variables y Estado
- Usa el panel "Variables" para inspeccionar el estado actual
- Hover sobre variables en el código para ver sus valores
- Usa la "Debug Console" para evaluar expresiones

### Breakpoints Condicionales
- Clic derecho en un breakpoint para establecer condiciones
- Útil para debugging de loops o eventos específicos

### Logging
- Los `std::cout` statements aparecerán en la terminal integrada
- Úsalos para trazar el flujo de ejecución

### Memory Debugging
- CodeLLDB permite inspección detallada de memoria
- Usa el panel "Memory" para análisis de bajo nivel

## Resolución de Problemas

### ❌ Error: "debugger shutdown unexpectedly"

Este es un problema común con CodeLLDB en Linux. Aquí están las soluciones:

#### Solución 1: Usar GDB en lugar de CodeLLDB
```bash
# En Zed, usa las configuraciones que empiezan con "Debug App (GDB)"
```

#### Solución 2: Verificar dependencias del sistema
```bash
# Instalar dependencias si faltan
sudo pacman -S gdb lldb  # Arch Linux
sudo apt install gdb lldb  # Ubuntu/Debian
```

#### Solución 3: Debugging manual con script
```bash
# Usar el script de test incluido
./test_debug.sh gdb
# O con LLDB
./test_debug.sh lldb
```

#### Solución 4: Configuración de entorno
```bash
# Asegurar que las variables de entorno están correctas
export DISPLAY=:0
export TERM=xterm-256color
```

### Simbolos de Debug No Encontrados
```bash
# Asegúrate de compilar en modo Debug
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

### Debugger No Se Conecta
1. Verifica que el ejecutable existe: `./build/app`
2. Comprueba permisos de ejecución: `chmod +x build/app`
3. Prueba debugging manual: `./test_debug.sh gdb`
4. Reinicia Zed si es necesario

### Breakpoints No Se Activan
1. Compila en modo Debug (no Release)
2. Verifica que los símbolos de debug están presentes: `file build/app`
3. Asegúrate que el archivo está guardado
4. Usa la configuración "Simple Debug (GDB)" como alternativa

### CodeLLDB vs GDB vs LLDB
- **GDB**: Más estable en Linux, recomendado para principiantes
- **LLDB**: Mejor para desarrollo moderno, pero puede tener problemas de compatibilidad
- **CodeLLDB**: Extensión de VS Code que a veces falla en Zed

## Estructura de Archivos de Configuración

```
.zed/
├── debug.json         # Configuraciones de debugging (múltiples opciones)
├── debug_simple.json  # Configuraciones simplificadas
├── tasks.json         # Tareas de build y run
└── settings.json      # Configuraciones del editor

# Archivos adicionales
├── test_debug.sh      # Script para debugging manual
└── DEBUG_GUIDE.md     # Esta guía
```

## Recursos Adicionales

- [Documentación de CodeLLDB](https://github.com/vadimcn/vscode-lldb)
- [CMake Debugging Guide](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html)
- [Saucer Framework](https://github.com/saucer/saucer)

---

¡Happy Debugging! 🐛🔍