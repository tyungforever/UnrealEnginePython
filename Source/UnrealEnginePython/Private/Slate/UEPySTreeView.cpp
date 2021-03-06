
#include "UnrealEnginePythonPrivatePCH.h"

#include "UEPySTreeView.h"


static PyObject *ue_PySTreeView_str(ue_PySTreeView *self)
{
	return PyUnicode_FromFormat("<unreal_engine.STreeView '%p'>",
		self->s_list_view.s_table_view_base.s_compound_widget.s_widget.s_widget);
}

static PyMethodDef ue_PySTreeView_methods[] = {
	{ NULL }  /* Sentinel */
};

PyTypeObject ue_PySTreeViewType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"unreal_engine.STreeView", /* tp_name */
	sizeof(ue_PySTreeView), /* tp_basicsize */
	0,                         /* tp_itemsize */
	0,       /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,                         /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)ue_PySTreeView_str,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,        /* tp_flags */
	"Unreal Engine STreeView",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	0,                         /* tp_iternext */
	ue_PySTreeView_methods,             /* tp_methods */
};


void ue_python_init_stree_view(PyObject *ue_module) {
	ue_PySTreeViewType.tp_new = PyType_GenericNew;

	ue_PySTreeViewType.tp_base = &ue_PySListViewType;

	if (PyType_Ready(&ue_PySTreeViewType) < 0)
		return;

	Py_INCREF(&ue_PySTreeViewType);
	PyModule_AddObject(ue_module, "STreeView", (PyObject *)&ue_PySTreeViewType);
}
