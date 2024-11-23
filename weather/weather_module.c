#include <Python.h>
#include "calculate.c"

static PyObject* py_calculate_mean(PyObject* self, PyObject* args) {
    PyObject *list_obj;
    if (!PyArg_ParseTuple(args, "O", &list_obj))
        return NULL;

    int size = PyList_Size(list_obj);
    float *data = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(list_obj, i);
        data[i] = PyFloat_AsDouble(item);
    }

    float result = calculate_mean(data, size);
    free(data);
    return Py_BuildValue("f", result);
}

static PyObject* py_calculate_std(PyObject* self, PyObject* args) {
    PyObject *list_obj;
    if (!PyArg_ParseTuple(args, "O", &list_obj))
        return NULL;

    int size = PyList_Size(list_obj);
    float *data = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(list_obj, i);
        data[i] = PyFloat_AsDouble(item);
    }

    float result = calculate_std(data, size);
    free(data);
    return Py_BuildValue("f", result);
}

static PyObject* py_calculate_median(PyObject* self, PyObject* args) {
    PyObject *list_obj;
    if (!PyArg_ParseTuple(args, "O", &list_obj))
        return NULL;

    int size = PyList_Size(list_obj);
    float *data = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(list_obj, i);
        data[i] = PyFloat_AsDouble(item);
    }

    float result = calculate_median(data, size);
    free(data);
    return Py_BuildValue("f", result);
}

static PyObject* py_calculate_mode(PyObject* self, PyObject* args) {
    PyObject *list_obj;
    if (!PyArg_ParseTuple(args, "O", &list_obj))
        return NULL;

    int size = PyList_Size(list_obj);
    float *data = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(list_obj, i);
        data[i] = PyFloat_AsDouble(item);
    }

    float result = calculate_mode(data, size);
    free(data);
    return Py_BuildValue("f", result);
}

static PyMethodDef WeatherMethods[] = {
    {"mean", py_calculate_mean, METH_VARARGS, "Calculate mean of data"},
    {"std", py_calculate_std, METH_VARARGS, "Calculate standard deviation"},
    {"median", py_calculate_median, METH_VARARGS, "Calculate median"},
    {"mode", py_calculate_mode, METH_VARARGS, "Calculate mode"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef weathermodule = {
    PyModuleDef_HEAD_INIT,
    "weather",
    NULL,
    -1,
    WeatherMethods
};

PyMODINIT_FUNC PyInit_weather(void) {
    return PyModule_Create(&weathermodule);
}
