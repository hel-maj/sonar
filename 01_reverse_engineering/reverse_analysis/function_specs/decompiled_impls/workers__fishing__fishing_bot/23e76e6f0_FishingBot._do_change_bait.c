/* ===== 23e76e6f0 workers.fishing.fishing_bot:FishingBot._do_change_bait ===== */
/* ghidra_name=FUN_23e76e6f0 entry=23e76e6f0 size=1738 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e76e6f0(longlong param_1,longlong param_2,longlong *param_3)

{
  undefined1 (*pauVar1) [16];
  code *pcVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong *plVar16;
  
  plVar10 = _DAT_23eedad90;
  pauVar1 = *(undefined1 (**) [16])(param_2 + 0x90);
  if (*(int *)(param_2 + 0x78) == 1) {
    if (param_3 == (longlong *)0x0) goto LAB_23e76e9b0;
    *param_3 = *param_3 + -1;
    if (*param_3 == 0) {
      (**(code **)(param_3[1] + 0x30))(param_3);
    }
    lVar11 = *(longlong *)(param_1 + 0x10);
    if ((((*(int *)(*(longlong *)(lVar11 + 0x28) + 0x160) == 0) && (*(int *)(lVar11 + 0x78) == 0))
        || (iVar9 = Py_MakePendingCalls(), -1 < iVar9)) ||
       (lVar12 = *(longlong *)(param_1 + 0x60), lVar12 == 0)) {
      if (*(int *)(lVar11 + 0x68) != 0) {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
      }
      plVar10 = *(longlong **)(param_1 + 0x90);
      if (plVar10 != (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        plVar14 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar3 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar10;
        *plVar10 = *plVar10 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        goto LAB_23e76e9b0;
      }
      goto LAB_23e76e7f2;
    }
  }
  else {
    *(undefined8 *)pauVar1[1] = 0;
    *pauVar1 = (undefined1  [16])0x0;
    *(undefined8 *)(pauVar1[2] + 8) = 0;
    *(undefined4 *)pauVar1[3] = 0;
    *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
    if (plVar10 == (longlong *)0x0) {
LAB_23e76e75f:
      plVar10 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedafe8,DAT_23eedaeb8,0x10);
      lVar11 = *plVar10;
      _DAT_23eedad90 = plVar10;
    }
    else {
      lVar11 = *plVar10;
      if (1 < lVar11) {
        *plVar10 = lVar11 + -1;
        goto LAB_23e76e75f;
      }
      if (plVar10[2] != 0) {
        *plVar10 = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        goto LAB_23e76e75f;
      }
    }
    lVar12 = *(longlong *)(param_1 + 0x38);
    *(longlong **)(param_2 + 0x50) = plVar10;
    *plVar10 = lVar11 + 1;
    lVar11 = *(longlong *)(lVar12 + 8);
    plVar10[7] = param_2;
    *(undefined4 *)(plVar10 + 8) = 0;
    plVar10[0xf] = lVar11;
    *(longlong **)(lVar12 + 8) = plVar10 + 9;
    if ((lVar11 != 0) &&
       (((*(char *)(lVar11 + 0x45) == '\x01' ||
         ((ulonglong)
          (*(longlong *)(lVar11 + 0x20) + 0xb8 +
          (longlong)*(int *)(*(longlong *)(lVar11 + 0x20) + 0xa8) * 2) <=
          *(ulonglong *)(lVar11 + 0x38))) && (plVar10[0xe] != 0)))) {
      plVar16 = *(longlong **)(lVar11 + 0x28);
      *(longlong **)(plVar10[0xe] + 0x10) = plVar16;
      if (plVar16 != (longlong *)0x0) {
        *plVar16 = *plVar16 + 1;
      }
    }
    plVar10 = *(longlong **)(param_1 + 0x138);
    *(longlong **)(param_2 + 0x68) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
LAB_23e76e7f2:
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xa0) + 0x10) + 8);
    pcVar2 = *(code **)(lVar11 + 0xe0);
    if (pcVar2 == (code *)0x0) {
      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                   *(undefined8 *)(lVar11 + 0x18));
    }
    else {
      plVar10 = (longlong *)(*pcVar2)();
      if (plVar10 != (longlong *)0x0) {
        plVar16 = *(longlong **)(*pauVar1 + 8);
        *(longlong **)(*pauVar1 + 8) = plVar10;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
          plVar10 = *(longlong **)(*pauVar1 + 8);
        }
        lVar11 = *plVar10;
        plVar16 = *(longlong **)*pauVar1;
        *(longlong **)*pauVar1 = plVar10;
        lVar11 = lVar11 + 1;
        *plVar10 = lVar11;
        if (plVar16 != (longlong *)0x0) {
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
            plVar10 = *(longlong **)*pauVar1;
          }
          lVar11 = *plVar10;
        }
        *plVar10 = lVar11 + 1;
        *(undefined4 *)(param_2 + 0x78) = 1;
        return plVar10;
      }
    }
    cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    if (cVar8 != '\0') {
      plVar10 = *(longlong **)(param_2 + 0x68);
      if (plVar10 != (longlong *)0x0) {
        *(undefined8 *)(param_2 + 0x68) = 0;
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))();
        }
      }
      plVar10 = *(longlong **)(*pauVar1 + 8);
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      plVar10 = *(longlong **)*pauVar1;
      *(undefined8 *)(*pauVar1 + 8) = 0;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      *(undefined8 *)*pauVar1 = 0;
      return (longlong *)0x0;
    }
LAB_23e76e9b0:
    lVar12 = *(longlong *)(param_1 + 0x60);
  }
  *(longlong *)(pauVar1[1] + 8) = lVar12;
  *(undefined8 *)pauVar1[2] = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(pauVar1[2] + 8) = *(undefined8 *)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar5 = *(undefined8 *)(pauVar1[1] + 8);
  uVar6 = *(undefined8 *)pauVar1[2];
  plVar10 = *(longlong **)(*pauVar1 + 8);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined **)pauVar1[1] = &DAT_23ec5dfc2;
  uVar4 = *(undefined8 *)(pauVar1[2] + 8);
  *(undefined4 *)pauVar1[5] = 0x514;
  *(undefined4 *)pauVar1[3] = 0;
  *(undefined8 *)(pauVar1[4] + 8) = uVar4;
  *(undefined8 *)(pauVar1[2] + 8) = 0;
  *(undefined8 *)(pauVar1[3] + 8) = uVar5;
  *(undefined8 *)pauVar1[4] = uVar6;
  *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
  if ((plVar10 == (longlong *)0x0) || (*plVar10 = *plVar10 + -1, *plVar10 != 0)) {
    uVar15 = 0x514;
  }
  else {
    (**(code **)(plVar10[1] + 0x30))();
    uVar15 = *(undefined4 *)pauVar1[5];
  }
  uVar4 = *(undefined8 *)(pauVar1[3] + 8);
  uVar5 = *(undefined8 *)pauVar1[4];
  *(undefined8 *)(*pauVar1 + 8) = 0;
  *(undefined4 *)pauVar1[3] = uVar15;
  *(undefined8 *)(pauVar1[1] + 8) = uVar4;
  uVar6 = *(undefined8 *)(pauVar1[4] + 8);
  *(undefined8 *)pauVar1[2] = uVar5;
  *(undefined8 *)(pauVar1[2] + 8) = uVar6;
  cVar8 = FUN_23a35d720(param_1,uVar4);
  puVar13 = DAT_23ed6a4f8;
  if (cVar8 != '\0') goto LAB_23e76eb5b;
  plVar10 = *(longlong **)(pauVar1[2] + 8);
  iVar9 = *(int *)pauVar1[3];
  plVar16 = *(longlong **)(param_2 + 0x50);
  if (plVar10 == (longlong *)0x0) {
    if (iVar9 == 0) {
      iVar9 = (int)plVar16[5];
    }
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar13 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar10 = *(longlong **)(pauVar1[2] + 8);
    }
    else {
      puVar7 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = (longlong *)0x0;
    }
    pcVar2 = _PyRuntime_exref;
    puVar13[2] = 0;
    puVar13[3] = plVar16;
    *plVar16 = *plVar16 + 1;
    lVar11 = *(longlong *)(pcVar2 + 0x1f8);
    *(undefined4 *)(puVar13 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(int *)((longlong)puVar13 + 0x24) = iVar9;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    uVar4 = puVar13[-1];
    puVar7 = *(undefined8 **)(lVar11 + 8);
    *puVar7 = puVar13 + -2;
    puVar13[-2] = lVar11;
    puVar13[-1] = (ulonglong)((uint)uVar4 & 3) | (ulonglong)puVar7;
    *(undefined8 **)(lVar11 + 8) = puVar13 + -2;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
LAB_23e76eb30:
    *(undefined8 **)(pauVar1[2] + 8) = puVar13;
    plVar16 = *(longlong **)(param_2 + 0x50);
  }
  else if ((iVar9 != 0) && ((longlong *)plVar10[3] != plVar16)) {
    if (DAT_23ed6a4f8 == (undefined8 *)0x0) {
      puVar13 = (undefined8 *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar14 = *(longlong **)(pauVar1[2] + 8);
    }
    else {
      puVar7 = (undefined8 *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = puVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar14 = plVar10;
    }
    pcVar2 = _PyRuntime_exref;
    puVar13[3] = plVar16;
    *plVar16 = *plVar16 + 1;
    lVar11 = *(longlong *)(pcVar2 + 0x1f8);
    *(undefined4 *)(puVar13 + 4) = 0xffffffff;
    *(int *)((longlong)puVar13 + 0x24) = iVar9;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    uVar4 = puVar13[-1];
    puVar7 = *(undefined8 **)(lVar11 + 8);
    *puVar7 = puVar13 + -2;
    puVar13[-2] = lVar11;
    puVar13[-1] = (ulonglong)((uint)uVar4 & 3) | (ulonglong)puVar7;
    *(undefined8 **)(lVar11 + 8) = puVar13 + -2;
    puVar13[2] = plVar10;
    *plVar10 = *plVar10 + 1;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    goto LAB_23e76eb30;
  }
  FUN_23e8bba40(plVar16,*(undefined8 *)pauVar1[1],0,*(undefined8 *)*pauVar1);
  plVar10 = _DAT_23eedad90;
  if (*(longlong **)(param_2 + 0x50) == _DAT_23eedad90) {
    *_DAT_23eedad90 = *_DAT_23eedad90 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    _DAT_23eedad90 = (longlong *)0x0;
  }
LAB_23e76eb5b:
  plVar10 = *(longlong **)(param_2 + 0x68);
  if (plVar10 != (longlong *)0x0) {
    *(undefined8 *)(param_2 + 0x68) = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  uVar15 = *(undefined4 *)pauVar1[3];
  uVar5 = *(undefined8 *)(pauVar1[1] + 8);
  uVar6 = *(undefined8 *)pauVar1[2];
  *(undefined4 *)pauVar1[3] = 0;
  uVar4 = *(undefined8 *)(pauVar1[2] + 8);
  plVar10 = *(longlong **)*pauVar1;
  *(undefined1 (*) [16])(pauVar1[1] + 8) = (undefined1  [16])0x0;
  *(undefined4 *)pauVar1[7] = uVar15;
  *(undefined8 *)(pauVar1[6] + 8) = uVar4;
  *(undefined8 *)(pauVar1[2] + 8) = 0;
  *(undefined8 *)(pauVar1[5] + 8) = uVar5;
  *(undefined8 *)pauVar1[6] = uVar6;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
    uVar15 = *(undefined4 *)pauVar1[7];
  }
  uVar4 = *(undefined8 *)(pauVar1[6] + 8);
  uVar5 = *(undefined8 *)(pauVar1[5] + 8);
  uVar6 = *(undefined8 *)pauVar1[6];
  *(undefined4 *)pauVar1[3] = uVar15;
  *(undefined8 *)*pauVar1 = 0;
  *(undefined8 *)(pauVar1[2] + 8) = uVar4;
  *(undefined8 *)(pauVar1[1] + 8) = uVar5;
  *(undefined8 *)pauVar1[2] = uVar6;
  FUN_23a33aa70(param_1,*(undefined8 *)(pauVar1[1] + 8),*(undefined8 *)pauVar1[2]);
  return (longlong *)0x0;
}
