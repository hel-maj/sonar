/* ===== 23e83d2f0 workers.fishing.trigger_monitor:363 ===== */
/* ghidra_name=FUN_23e83d2f0 entry=23e83d2f0 size=2781 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e83d2f0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  longlong *plStack_68;
  undefined8 uStack_60;
  
  plVar11 = _DAT_23eede420;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede420 == (longlong *)0x0) {
LAB_23e83d335:
    _DAT_23eede420 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede418,DAT_23eede5a0,0x10);
  }
  else {
    lVar13 = *_DAT_23eede420;
    if (1 < lVar13) {
      *_DAT_23eede420 = lVar13 + -1;
      goto LAB_23e83d335;
    }
    if (_DAT_23eede420[2] != 0) {
      *_DAT_23eede420 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e83d335;
    }
  }
  plVar5 = _DAT_23eede420;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eede420 + 9;
  lVar10 = *(longlong *)(lVar13 + 8);
  _DAT_23eede420[0xf] = lVar10;
  *(longlong **)(lVar13 + 8) = plVar11;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar12 = _DAT_23eedc318;
  *(undefined4 *)(plVar5 + 8) = 0;
  iVar8 = FUN_23e97a530(plVar1,uVar12);
  if (iVar8 == -1) {
LAB_23e83dc18:
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar16 = 0x16d;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e83d8a3;
  }
  if (iVar8 == 1) {
    iVar8 = FUN_23e97a530(plVar2,_DAT_23eedc320);
    plVar11 = _DAT_23eedc328;
    if (iVar8 == -1) goto LAB_23e83dc18;
    if (iVar8 == 1) {
      *_DAT_23eedc328 = *_DAT_23eedc328 + 1;
      goto LAB_23e83d7c3;
    }
  }
  iVar8 = FUN_23e97a530(plVar1,_DAT_23eedc330);
  if (iVar8 == -1) {
LAB_23e83dc48:
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar16 = 0x16f;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e83d8a3;
  }
  if (iVar8 == 1) {
    iVar8 = FUN_23e97a530(plVar2,_DAT_23eedc338);
    plVar11 = _DAT_23eedc340;
    if (iVar8 == -1) goto LAB_23e83dc48;
    if (iVar8 == 1) {
      *_DAT_23eedc340 = *_DAT_23eedc340 + 1;
      goto LAB_23e83d7c3;
    }
  }
  plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
  plVar11 = _DAT_23eedc348;
  if ((plVar9 == (longlong *)0x0) || (lVar13 = *plVar9, lVar13 == 0)) {
LAB_23e83dc00:
    PyErr_PrintEx(0);
    Py_Exit(1);
    goto LAB_23e83dc18;
  }
  lVar10 = *(longlong *)(param_1 + 0x10);
  plVar14 = *(longlong **)(lVar10 + 0xe30);
  if (plVar14 == (longlong *)0x0) {
    plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
  }
  else {
    lVar3 = plVar14[3];
    *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
    *(longlong *)(lVar10 + 0xe30) = lVar3;
    *plVar14 = 1;
  }
  pcVar7 = _PyRuntime_exref;
  plVar14[6] = 0;
  *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
  lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
  lVar3 = plVar14[-1];
  puVar4 = *(undefined8 **)(lVar10 + 8);
  *puVar4 = plVar14 + -2;
  plVar14[-2] = lVar10;
  plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar10 + 8) = plVar14 + -2;
  plVar9 = DAT_23ed6a4c0;
  *plVar11 = *plVar11 + 1;
  plVar14[3] = (longlong)plVar11;
  uVar12 = DAT_23ed6cd28;
  if (plVar9 == (longlong *)0x0) {
    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar9 == (longlong *)0x0) goto LAB_23e83dc00;
    *plVar9 = *plVar9 + 1;
    DAT_23ed6a4c0 = plVar9;
  }
  uStack_60 = uVar12;
  plStack_68 = plVar1;
  lVar10 = FUN_23e94ed00(param_1,plVar9,&plStack_68);
  if (lVar10 == 0) {
LAB_23e83d870:
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar16 = 0x172;
    uVar15 = 0x172;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar14 = *plVar14 + -1;
    lVar13 = *plVar14;
  }
  else {
    plVar14[4] = lVar10;
    plVar11 = _DAT_23eedc350;
    *_DAT_23eedc350 = *_DAT_23eedc350 + 1;
    plVar14[5] = (longlong)plVar11;
    uVar12 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar11 == (longlong *)0x0) goto LAB_23e83dc00;
      *plVar11 = *plVar11 + 1;
      DAT_23ed6a4c0 = plVar11;
    }
    uStack_60 = uVar12;
    plStack_68 = plVar2;
    lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_68);
    if (lVar10 == 0) goto LAB_23e83d870;
    plVar14[6] = lVar10;
    plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (plVar11 == (longlong *)0x0) {
LAB_23e83dce0:
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar16 = 0x172;
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = DAT_23ed6a4f8;
      goto joined_r0x00023e83d8a3;
    }
    *(undefined4 *)(plVar5 + 5) = 0x172;
    plVar9 = (longlong *)FUN_23e914090(param_1,lVar13);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e83dce0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar5 + 5) = 0x173;
    plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar12,_DAT_23eedc358);
    if (plVar11 == (longlong *)0x0) {
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      uVar6 = *(undefined8 *)(param_1 + 0x60);
      uVar16 = 0x173;
      plVar11 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = DAT_23ed6a4f8;
      goto joined_r0x00023e83d8a3;
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar11 = _DAT_23eedc360;
    lVar13 = *(longlong *)(param_1 + 0x10);
    plVar14 = *(longlong **)(lVar13 + 0xe38);
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
    }
    else {
      lVar10 = plVar14[3];
      *(int *)(lVar13 + 0xec8) = *(int *)(lVar13 + 0xec8) + -1;
      *(longlong *)(lVar13 + 0xe38) = lVar10;
      *plVar14 = 1;
    }
    pcVar7 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
    lVar13 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined1 (*) [16])(plVar14 + 6) = (undefined1  [16])0x0;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar10 = plVar14[-1];
    puVar4 = *(undefined8 **)(lVar13 + 8);
    *puVar4 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
    plVar9 = DAT_23ed6a4c0;
    *plVar11 = *plVar11 + 1;
    plVar14[3] = (longlong)plVar11;
    uVar12 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) goto LAB_23e83dc00;
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    uStack_60 = uVar12;
    plStack_68 = plVar1;
    lVar13 = FUN_23e94ed00(param_1,plVar9,&plStack_68);
    if (lVar13 != 0) {
      plVar14[4] = lVar13;
      plVar11 = _DAT_23eedc350;
      *_DAT_23eedc350 = *_DAT_23eedc350 + 1;
      plVar14[5] = (longlong)plVar11;
      uVar12 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar11 == (longlong *)0x0) goto LAB_23e83dc00;
        *plVar11 = *plVar11 + 1;
        DAT_23ed6a4c0 = plVar11;
      }
      uStack_60 = uVar12;
      plStack_68 = plVar2;
      lVar13 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_68);
      if (lVar13 != 0) {
        plVar14[6] = lVar13;
        plVar11 = _DAT_23eedc368;
        *_DAT_23eedc368 = *_DAT_23eedc368 + 1;
        plVar14[7] = (longlong)plVar11;
        lVar13 = PyUnicode_Join(DAT_23ed6cd28,plVar14);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (lVar13 != 0) {
          lVar10 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar10 + 0xe20);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar3 = plVar11[3];
            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
            *(longlong *)(lVar10 + 0xe20) = lVar3;
            *plVar11 = 1;
          }
          lVar10 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar11[-1];
          puVar4 = *(undefined8 **)(lVar10 + 8);
          *puVar4 = plVar11 + -2;
          plVar5 = _DAT_23eedc058;
          plVar11[-2] = lVar10;
          plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
          *(longlong **)(lVar10 + 8) = plVar11 + -2;
          plVar11[3] = lVar13;
          *plVar5 = *plVar5 + 1;
          plVar11[4] = (longlong)plVar5;
LAB_23e83d7c3:
          lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar5 = *(longlong **)(lVar13 + 0x28);
          plVar9 = (longlong *)plVar5[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
          *(undefined4 *)(plVar5 + 8) = 0xffffffff;
          if (plVar9 != (longlong *)0x0) {
            plVar5[2] = 0;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))();
            }
          }
          *plVar5 = *plVar5 + -1;
          if (*plVar5 == 0) {
            (**(code **)(plVar5[1] + 0x30))(plVar5);
          }
          plVar5[0xf] = 0;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return plVar11;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return plVar11;
        }
        uVar12 = *(undefined8 *)(param_1 + 0x68);
        uVar6 = *(undefined8 *)(param_1 + 0x60);
        uVar16 = 0x174;
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e83d8a3;
      }
    }
    uVar12 = *(undefined8 *)(param_1 + 0x68);
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar16 = 0x174;
    uVar15 = 0x174;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar14 = *plVar14 + -1;
    lVar13 = *plVar14;
  }
  plVar9 = DAT_23ed6a4f8;
  if (lVar13 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
    plVar9 = DAT_23ed6a4f8;
    uVar16 = uVar15;
  }
joined_r0x00023e83d8a3:
  DAT_23ed6a4f8 = plVar9;
  if (plVar11 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar13 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar10 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar13 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar13;
    plVar9[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar13 + 8) = plVar9 + -2;
    plVar14 = plVar9;
  }
  else {
    plVar14 = plVar11;
    if ((longlong *)plVar11[3] != plVar5) {
      if (plVar9 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar9;
        *plVar9 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar7 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar13 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar16;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
      lVar10 = plVar9[-1];
      puVar4 = *(undefined8 **)(lVar13 + 8);
      *puVar4 = plVar9 + -2;
      plVar9[-2] = lVar13;
      plVar9[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar4;
      lVar10 = *plVar11;
      *(longlong **)(lVar13 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar11;
      plVar14 = plVar9;
      if (lVar10 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e407,plVar1,plVar2);
  if (_DAT_23eede420 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede420 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar13 + 0x28);
  plVar5 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar6,uVar12,plVar14);
  return (longlong *)0x0;
}
