/* ===== 23e86bd20 workers.fishing.window_capture:152 ===== */
/* ghidra_name=FUN_23e86bd20 entry=23e86bd20 size=1864 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e86bd20(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong *plVar14;
  undefined8 uVar15;
  longlong lStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  plVar11 = _DAT_23eedb9c8;
  plVar1 = (longlong *)*param_3;
  if (*(code **)(_DAT_23eedb9c8[1] + 0xd8) == (code *)0x0) {
    plVar9 = (longlong *)FUN_23a33a530(PySeqIter_Type_exref);
    plVar9[2] = 0;
    *plVar11 = *plVar11 + 1;
    plVar9[3] = (longlong)plVar11;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar9[-1];
    plVar11 = *(longlong **)(lVar10 + 8);
    *plVar11 = (longlong)(plVar9 + -2);
    plVar9[-2] = lVar10;
    plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar11;
    *(longlong **)(lVar10 + 8) = plVar9 + -2;
  }
  else {
    plVar9 = (longlong *)(**(code **)(_DAT_23eedb9c8[1] + 0xd8))(_DAT_23eedb9c8);
  }
  plVar11 = _DAT_23eede240;
  if (_DAT_23eede240 != (longlong *)0x0) {
    lVar10 = *_DAT_23eede240;
    if (lVar10 < 2) {
      if (_DAT_23eede240[2] == 0) goto LAB_23e86bda5;
      *_DAT_23eede240 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
    else {
      *_DAT_23eede240 = lVar10 + -1;
    }
  }
  _DAT_23eede240 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede238,DAT_23eede308,0x10);
LAB_23e86bda5:
  plVar6 = _DAT_23eede240;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eede240 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eede240[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar11;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar11 = (longlong *)0x0;
  do {
    plVar12 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
    if (plVar12 == (longlong *)0x0) {
      cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
      if (cVar7 != '\0') {
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar6 = *(longlong **)(lVar10 + 0x28);
        plVar12 = (longlong *)plVar6[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar6 + 8) = 0xffffffff;
        if (plVar12 != (longlong *)0x0) {
          plVar6[2] = 0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
          }
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        plVar6[0xf] = 0;
        if (plVar11 == (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar13 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        }
        else {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar13 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
        }
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar13;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar13;
      }
      lStack_90 = *(longlong *)(param_1 + 0x60);
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if (plVar11 != (longlong *)0x0) goto LAB_23e86bf96;
      goto LAB_23e86bfa3;
    }
    if (plVar11 == (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
      lVar10 = FUN_23e8da9a0();
      if (lVar10 != 0) goto LAB_23e86be55;
LAB_23e86c135:
      FUN_23e915740(param_1,&uStack_68,DAT_23eedb790);
      uStack_78 = uStack_58;
      uStack_88 = uStack_68;
      uStack_80 = uStack_60;
LAB_23e86c179:
      FUN_23a35d6b0(&uStack_88);
    }
    else {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        lVar10 = *plVar12;
      }
      else {
        lVar10 = *plVar12;
      }
      *plVar12 = lVar10 + 1;
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      lVar10 = FUN_23e8da9a0();
      if (lVar10 == 0) goto LAB_23e86c135;
LAB_23e86be55:
      *(undefined4 *)(plVar6 + 5) = 0x9c;
      plVar11 = (longlong *)FUN_23e915840(param_1,lVar10,_DAT_23eedb9b8,plVar12);
      if (plVar11 == (longlong *)0x0) {
        uStack_78 = *(undefined8 *)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_88 = *(undefined8 *)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e86c179;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
    lVar10 = *(longlong *)(param_1 + 0x10);
    plVar11 = plVar12;
    if (((*(int *)(*(longlong *)(lVar10 + 0x28) + 0x160) != 0) || (*(int *)(lVar10 + 0x78) != 0)) &&
       ((iVar8 = Py_MakePendingCalls(), iVar8 < 0 &&
        (lStack_90 = *(longlong *)(param_1 + 0x60), lStack_90 != 0)))) goto LAB_23e86bf7e;
    if (*(int *)(lVar10 + 0x68) == 0) {
      plVar12 = *(longlong **)(param_1 + 0x90);
    }
    else {
      PyEval_SaveThread();
      PyEval_AcquireThread(param_1);
      plVar12 = *(longlong **)(param_1 + 0x90);
    }
  } while (plVar12 == (longlong *)0x0);
  plVar14 = *(longlong **)(param_1 + 0x60);
  plVar3 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar4 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar12;
  *plVar12 = *plVar12 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))();
  }
  if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  lStack_90 = *(longlong *)(param_1 + 0x60);
LAB_23e86bf7e:
  plVar12 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar15 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e86bf96:
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23e86bfa3:
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9 = DAT_23ed6a4f8;
  if (plVar12 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[3] = (longlong)plVar6;
    plVar9[2] = 0;
    *plVar6 = *plVar6 + 1;
    plVar9[4] = 0x9affffffff;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar10;
    plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar9 + -2;
    plVar14 = plVar9;
  }
  else {
    plVar14 = plVar12;
    if ((longlong *)plVar12[3] != plVar6) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar9[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      plVar9[4] = 0x9affffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar9[-1];
      puVar5 = *(undefined8 **)(lVar10 + 8);
      *puVar5 = plVar9 + -2;
      plVar9[-2] = lVar10;
      plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
      lVar2 = *plVar12;
      *(longlong **)(lVar10 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar12;
      plVar14 = plVar9;
      if (lVar2 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5e407,plVar1,plVar11);
  if (_DAT_23eede240 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eede240 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar10 + 0x28);
  plVar6 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,lStack_90,uVar15,plVar14);
  return (code *)0x0;
}
