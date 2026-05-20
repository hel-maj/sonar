/* ===== 23e7491b0 workers.fishing.fishing_bot:FishingBot._is_trigger_active ===== */
/* ghidra_name=FUN_23e7491b0 entry=23e7491b0 size=2107 */

code * FUN_23e7491b0(longlong param_1,longlong param_2,longlong *param_3)

{
  undefined1 (*pauVar1) [16];
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong lVar14;
  longlong *plVar15;
  code *pcVar16;
  bool bVar17;
  longlong local_48;
  longlong *local_40;
  
  plVar9 = DAT_23eedae48;
  pauVar1 = *(undefined1 (**) [16])(param_2 + 0x90);
  if (*(int *)(param_2 + 0x78) == 1) {
    FUN_23e8bc3f0(pauVar1[3] + 8,&local_40,8,&local_48,8,0);
    if (param_3 != (longlong *)0x0) {
      *param_3 = *param_3 + -1;
      if (*param_3 == 0) {
        (**(code **)(param_3[1] + 0x30))(param_3);
      }
      lVar14 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar14 + 0x28) + 0x160) == 0) && (*(int *)(lVar14 + 0x78) == 0))
          || (iVar8 = Py_MakePendingCalls(), -1 < iVar8)) || (*(longlong *)(param_1 + 0x60) == 0)) {
        if (*(int *)(lVar14 + 0x68) != 0) {
          PyEval_SaveThread();
          PyEval_AcquireThread(param_1);
        }
        plVar9 = *(longlong **)(param_1 + 0x90);
        if (plVar9 != (longlong *)0x0) {
          plVar15 = *(longlong **)(param_1 + 0x60);
          plVar12 = *(longlong **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x90) = 0;
          plVar3 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar9;
          *plVar9 = *plVar9 + 1;
          *(undefined8 *)(param_1 + 0x68) = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
            (**(code **)(plVar3[1] + 0x30))(plVar3);
          }
          goto LAB_23e749545;
        }
        goto LAB_23e7492c7;
      }
      goto LAB_23e749545;
    }
LAB_23e7497c0:
    *(undefined8 *)(pauVar1[1] + 8) = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)pauVar1[2] = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(pauVar1[2] + 8) = *(undefined8 *)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7497e8:
    uVar13 = 0x23f;
    *(undefined **)pauVar1[1] = &DAT_23ec5df8e;
  }
  else {
    *(undefined8 *)pauVar1[1] = 0;
    *pauVar1 = (undefined1  [16])0x0;
    *(undefined8 *)(pauVar1[2] + 8) = 0;
    *(undefined4 *)pauVar1[3] = 0;
    *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
    if (plVar9 == (longlong *)0x0) {
LAB_23e749222:
      plVar9 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedb000,DAT_23eedaeb8,0x18);
      lVar14 = *plVar9;
      DAT_23eedae48 = plVar9;
    }
    else {
      lVar14 = *plVar9;
      if (1 < lVar14) {
        *plVar9 = lVar14 + -1;
        goto LAB_23e749222;
      }
      if (plVar9[2] != 0) {
        *plVar9 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        goto LAB_23e749222;
      }
    }
    lVar2 = *(longlong *)(param_1 + 0x38);
    *(longlong **)(param_2 + 0x50) = plVar9;
    *plVar9 = lVar14 + 1;
    lVar14 = *(longlong *)(lVar2 + 8);
    plVar9[7] = param_2;
    *(undefined4 *)(plVar9 + 8) = 0;
    plVar9[0xf] = lVar14;
    *(longlong **)(lVar2 + 8) = plVar9 + 9;
    if ((lVar14 != 0) &&
       (((*(char *)(lVar14 + 0x45) == '\x01' ||
         ((ulonglong)
          (*(longlong *)(lVar14 + 0x20) + 0xb8 +
          (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
          *(ulonglong *)(lVar14 + 0x38))) && (plVar9[0xe] != 0)))) {
      plVar15 = *(longlong **)(lVar14 + 0x28);
      *(longlong **)(plVar9[0xe] + 0x10) = plVar15;
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
      }
    }
    plVar9 = *(longlong **)(param_1 + 0x138);
    *(longlong **)(param_2 + 0x68) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
LAB_23e7492c7:
    lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xa8) + 0x10) + 8);
    pcVar16 = *(code **)(lVar14 + 0xe0);
    if (pcVar16 == (code *)0x0) {
      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                   *(undefined8 *)(lVar14 + 0x18));
    }
    else {
      plVar9 = (longlong *)(*pcVar16)();
      if (plVar9 != (longlong *)0x0) {
        plVar15 = *(longlong **)(*pauVar1 + 8);
        *(longlong **)(*pauVar1 + 8) = plVar9;
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
          plVar9 = *(longlong **)(*pauVar1 + 8);
        }
        plVar15 = *(longlong **)*pauVar1;
        *(longlong **)*pauVar1 = plVar9;
        *plVar9 = *plVar9 + 1;
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))();
          plVar9 = *(longlong **)*pauVar1;
        }
        lVar14 = *(longlong *)(*(longlong *)(param_2 + 0xa0) + 0x10);
        local_40 = plVar9;
        if (lVar14 != 0) {
          local_48 = lVar14;
          iVar8 = PySequence_Contains();
          *(int *)(pauVar1[3] + 4) = iVar8;
          if (iVar8 != -1) {
            pcVar16 = _Py_TrueStruct_exref;
            if (iVar8 != 1) {
              pcVar16 = _Py_FalseStruct_exref;
            }
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
            FUN_23e8bc390(pauVar1[3] + 8,&local_40,8,&local_48,8,0);
            *(undefined4 *)(param_2 + 0x78) = 1;
            return pcVar16;
          }
          goto LAB_23e7497c0;
        }
        if (((*(byte *)(DAT_23eed90b8 + 0x20) & 0x40) == 0) ||
           ((*(byte *)(DAT_23eed90b8 + 0x20) & 0x20) == 0)) {
          lVar14 = *(longlong *)(DAT_23eed90b8 + 0x38);
        }
        else {
          lVar14 = DAT_23eed90b8 + 0x30;
        }
        uVar10 = PyUnicode_FromFormat
                           ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                            ,lVar14);
        pcVar16 = *(code **)PyExc_NameError_exref;
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
        bVar17 = pcVar16 != _Py_NoneStruct_exref;
        *(undefined8 *)(pauVar1[2] + 8) = 0;
        *(code **)(pauVar1[1] + 8) = pcVar16;
        *(undefined8 *)pauVar1[2] = uVar10;
        if (bVar17) {
          FUN_23e91b1b0(param_1,pauVar1[1] + 8,pauVar1 + 2,pauVar1[2] + 8);
          uVar10 = *(undefined8 *)pauVar1[2];
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uVar10);
        goto LAB_23e7497e8;
      }
    }
    cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    if (cVar7 != '\0') {
      plVar9 = *(longlong **)(param_2 + 0x68);
      if (plVar9 != (longlong *)0x0) {
        *(undefined8 *)(param_2 + 0x68) = 0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
      }
      plVar9 = *(longlong **)(*pauVar1 + 8);
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))();
      }
      plVar9 = *(longlong **)*pauVar1;
      *(undefined8 *)(*pauVar1 + 8) = 0;
      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
        (**(code **)(plVar9[1] + 0x30))();
      }
      *(undefined8 *)*pauVar1 = 0;
      return (code *)0x0;
    }
LAB_23e749545:
    uVar13 = 0x23e;
    *(undefined8 *)(pauVar1[1] + 8) = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)pauVar1[2] = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(pauVar1[2] + 8) = *(undefined8 *)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined **)pauVar1[1] = &DAT_23ec5df8e;
  }
  uVar4 = *(undefined8 *)(pauVar1[1] + 8);
  uVar5 = *(undefined8 *)pauVar1[2];
  uVar10 = *(undefined8 *)(pauVar1[2] + 8);
  *(undefined4 *)pauVar1[0x45] = uVar13;
  plVar9 = *(longlong **)(*pauVar1 + 8);
  *(undefined4 *)pauVar1[3] = 0;
  *(undefined8 *)(pauVar1[0x44] + 8) = uVar10;
  *(undefined8 *)(pauVar1[2] + 8) = 0;
  *(undefined8 *)(pauVar1[0x43] + 8) = uVar4;
  *(undefined8 *)pauVar1[0x44] = uVar5;
  *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))();
    uVar13 = *(undefined4 *)pauVar1[0x45];
  }
  uVar10 = *(undefined8 *)(pauVar1[0x43] + 8);
  uVar4 = *(undefined8 *)pauVar1[0x44];
  *(undefined4 *)pauVar1[3] = uVar13;
  *(undefined8 *)(*pauVar1 + 8) = 0;
  *(undefined8 *)(pauVar1[1] + 8) = uVar10;
  uVar5 = *(undefined8 *)(pauVar1[0x44] + 8);
  *(undefined8 *)pauVar1[2] = uVar4;
  *(undefined8 *)(pauVar1[2] + 8) = uVar5;
  cVar7 = FUN_23a35d720(param_1,uVar10);
  puVar11 = DAT_23ed6a4f8;
  if (cVar7 != '\0') goto LAB_23e749717;
  plVar9 = *(longlong **)(pauVar1[2] + 8);
  iVar8 = *(int *)pauVar1[3];
  plVar15 = *(longlong **)(param_2 + 0x50);
  if (plVar9 == (longlong *)0x0) {
    if (iVar8 == 0) {
      iVar8 = (int)plVar15[5];
    }
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar11 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar9 = *(longlong **)(pauVar1[2] + 8);
    }
    else {
      puVar6 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar9 = (longlong *)0x0;
    }
    pcVar16 = _PyRuntime_exref;
    puVar11[2] = 0;
    puVar11[3] = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar14 = *(longlong *)(pcVar16 + 0x1f8);
    *(undefined4 *)(puVar11 + 4) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(int *)((longlong)puVar11 + 0x24) = iVar8;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    uVar10 = puVar11[-1];
    puVar6 = *(undefined8 **)(lVar14 + 8);
    *puVar6 = puVar11 + -2;
    puVar11[-2] = lVar14;
    puVar11[-1] = (ulonglong)((uint)uVar10 & 3) | (ulonglong)puVar6;
    *(undefined8 **)(lVar14 + 8) = puVar11 + -2;
    if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
LAB_23e7496e0:
    *(undefined8 **)(pauVar1[2] + 8) = puVar11;
    plVar15 = *(longlong **)(param_2 + 0x50);
  }
  else if ((iVar8 != 0) && ((longlong *)plVar9[3] != plVar15)) {
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar11 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar12 = *(longlong **)(pauVar1[2] + 8);
    }
    else {
      puVar6 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar12 = plVar9;
    }
    pcVar16 = _PyRuntime_exref;
    puVar11[3] = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar14 = *(longlong *)(pcVar16 + 0x1f8);
    *(undefined4 *)(puVar11 + 4) = 0xffffffff;
    *(int *)((longlong)puVar11 + 0x24) = iVar8;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    uVar10 = puVar11[-1];
    puVar6 = *(undefined8 **)(lVar14 + 8);
    *puVar6 = puVar11 + -2;
    puVar11[-2] = lVar14;
    puVar11[-1] = (ulonglong)((uint)uVar10 & 3) | (ulonglong)puVar6;
    *(undefined8 **)(lVar14 + 8) = puVar11 + -2;
    puVar11[2] = plVar9;
    *plVar9 = *plVar9 + 1;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    goto LAB_23e7496e0;
  }
  FUN_23e8bba40(plVar15,*(undefined8 *)pauVar1[1],0,*(undefined8 *)*pauVar1,
                *(undefined8 *)(param_2 + 0xa0));
  plVar9 = DAT_23eedae48;
  if (*(longlong **)(param_2 + 0x50) == DAT_23eedae48) {
    *DAT_23eedae48 = *DAT_23eedae48 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    DAT_23eedae48 = (longlong *)0x0;
  }
LAB_23e749717:
  plVar9 = *(longlong **)(param_2 + 0x68);
  if (plVar9 != (longlong *)0x0) {
    *(undefined8 *)(param_2 + 0x68) = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  uVar13 = *(undefined4 *)pauVar1[3];
  uVar4 = *(undefined8 *)(pauVar1[1] + 8);
  uVar5 = *(undefined8 *)pauVar1[2];
  *(undefined4 *)pauVar1[3] = 0;
  uVar10 = *(undefined8 *)(pauVar1[2] + 8);
  plVar9 = *(longlong **)*pauVar1;
  *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
  *(undefined4 *)pauVar1[0x47] = uVar13;
  *(undefined8 *)(pauVar1[0x46] + 8) = uVar10;
  *(undefined8 *)(pauVar1[2] + 8) = 0;
  *(undefined8 *)(pauVar1[0x45] + 8) = uVar4;
  *(undefined8 *)pauVar1[0x46] = uVar5;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))();
    uVar13 = *(undefined4 *)pauVar1[0x47];
  }
  uVar10 = *(undefined8 *)(pauVar1[0x46] + 8);
  *(undefined4 *)pauVar1[3] = uVar13;
  uVar4 = *(undefined8 *)(pauVar1[0x45] + 8);
  uVar5 = *(undefined8 *)pauVar1[0x46];
  *(undefined8 *)*pauVar1 = 0;
  *(undefined8 *)(pauVar1[2] + 8) = uVar10;
  *(undefined8 *)(pauVar1[1] + 8) = uVar4;
  *(undefined8 *)pauVar1[2] = uVar5;
  FUN_23a33aa70(param_1,*(undefined8 *)(pauVar1[1] + 8),*(undefined8 *)pauVar1[2]);
  return (code *)0x0;
}
