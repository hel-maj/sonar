/* ===== 23e7e6b30 workers.fishing.memory_fish_read:99 ===== */
/* ghidra_name=FUN_23e7e6b30 entry=23e7e6b30 size=6777 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7e6b30(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  code *pcVar18;
  code *pcVar19;
  longlong lVar20;
  undefined4 uVar21;
  longlong *plVar22;
  longlong *plVar23;
  longlong *plStack_c8;
  code *pcStack_c0;
  code *pcStack_b8;
  longlong *plStack_b0;
  undefined1 auStack_88 [16];
  code *pcStack_78;
  undefined1 auStack_68 [16];
  code *pcStack_58;
  
  plVar10 = _DAT_23eedeb38;
  plVar1 = (longlong *)*param_3;
  pcStack_58 = (code *)0x0;
  auStack_68 = (undefined1  [16])0x0;
  if (_DAT_23eedeb38 == (longlong *)0x0) {
LAB_23e7e6b85:
    _DAT_23eedeb38 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeb30,DAT_23eedebc0);
  }
  else {
    lVar9 = *_DAT_23eedeb38;
    if (1 < lVar9) {
      *_DAT_23eedeb38 = lVar9 + -1;
      goto LAB_23e7e6b85;
    }
    if (_DAT_23eedeb38[2] != 0) {
      *_DAT_23eedeb38 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7e6b85;
    }
  }
  plVar22 = _DAT_23eedeb38;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedeb38 + 9;
  lVar2 = *(longlong *)(lVar9 + 8);
  _DAT_23eedeb38[0xf] = lVar2;
  *(longlong **)(lVar9 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar22[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar22[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar22 = *plVar22 + 1;
  *(undefined4 *)(plVar22 + 8) = 0;
  lVar9 = FUN_23e8dd670();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,auStack_68,_DAT_23eeddd20);
    plStack_b0 = (longlong *)auStack_68._0_8_;
    pcStack_c0 = (code *)auStack_68._8_8_;
    plVar10 = (longlong *)0x0;
    if (pcStack_58 != (code *)0x0) {
      if (*(longlong **)(pcStack_58 + 0x18) == plVar22) {
        plVar23 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        pcVar18 = pcStack_58;
        goto LAB_23e7e7930;
      }
      plVar23 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      uVar21 = 100;
      pcStack_b8 = _PyRuntime_exref;
      goto LAB_23e7e77e0;
    }
    plVar23 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    uVar21 = 100;
    pcStack_b8 = _PyRuntime_exref;
    goto LAB_23e7e7f03;
  }
  iVar8 = PySequence_Contains(plVar1,lVar9);
  if (iVar8 == -1) {
    plStack_b0 = *(longlong **)(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    auStack_68._8_8_ = pcStack_c0;
    auStack_68._0_8_ = plStack_b0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar18 == (code *)0x0) {
      pcStack_b8 = _PyRuntime_exref;
      plVar23 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      uVar21 = 100;
      plStack_c8 = (longlong *)0x0;
      pcStack_58 = (code *)0x0;
      goto LAB_23e7e7f03;
    }
    if (*(longlong **)(pcVar18 + 0x18) != plVar22) {
      pcStack_b8 = _PyRuntime_exref;
      plVar23 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      uVar21 = 100;
      plStack_c8 = (longlong *)0x0;
      pcStack_58 = pcVar18;
      goto LAB_23e7e77e0;
    }
LAB_23e7e7910:
    plVar23 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e7e7930;
  }
  if (iVar8 == 0) {
    lVar9 = *(longlong *)(param_1 + 0x10);
    if (*(int *)(lVar9 + 0x1188) == 0) {
      plVar16 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    }
    else {
      iVar8 = *(int *)(lVar9 + 0x1188) + -1;
      *(int *)(lVar9 + 0x1188) = iVar8;
      plVar16 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar8 * 8);
      *plVar16 = 1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[4] = 0;
    lVar9 = *(longlong *)(pcVar18 + 0x1f8);
    plVar16[3] = 0;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar2 = plVar16[-1];
    puVar17 = *(undefined8 **)(lVar9 + 8);
    *puVar17 = plVar16 + -2;
    plVar16[-2] = lVar9;
    plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar9 + 8) = plVar16 + -2;
    goto LAB_23e7e6cbe;
  }
  plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeddd28);
  lVar9 = _DAT_23eeddd30;
  if (plVar16 == (longlong *)0x0) {
LAB_23e7e73a0:
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    pcStack_58 = (code *)0x0;
    plVar11 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    auStack_68 = (undefined1  [16])0x0;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    pcStack_78 = (code *)plVar10;
    if (plVar10 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar6 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar6;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar22;
      *plVar22 = *plVar22 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x67ffffffff;
      pcStack_b8 = _PyRuntime_exref;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar17 = *(undefined8 **)(lVar9 + 8);
      *puVar17 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      if ((pcStack_78 != (code *)0x0) &&
         (*(longlong *)pcStack_78 = *(longlong *)pcStack_78 + -1, *(longlong *)pcStack_78 == 0)) {
        (**(code **)(*(longlong *)((longlong)pcStack_78 + 8) + 0x30))(pcStack_78);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar6 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar6;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar22;
      *plVar22 = *plVar22 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x67ffffffff;
      pcStack_b8 = _PyRuntime_exref;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar17 = *(undefined8 **)(lVar9 + 8);
      *puVar17 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      *(longlong **)(pcVar18 + 0x10) = plVar10;
      *plVar10 = *plVar10 + 1;
      if ((pcStack_78 != (code *)0x0) &&
         (*(longlong *)pcStack_78 = *(longlong *)pcStack_78 + -1, *(longlong *)pcStack_78 == 0)) {
        (**(code **)(*(longlong *)((longlong)pcStack_78 + 8) + 0x30))(pcStack_78);
      }
    }
    pcVar6 = _Py_NoneStruct_exref;
    pcStack_78 = pcVar18;
    if (((code *)auStack_88._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_88._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8);
    }
    plVar10 = *(longlong **)(auStack_88._8_8_ + 0x28);
    if (pcStack_78 == pcVar6) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = pcStack_78;
      if (pcStack_78 != (code *)0x0) {
        *(longlong *)pcStack_78 = *(longlong *)pcStack_78 + 1;
      }
    }
    *(code **)(auStack_88._8_8_ + 0x28) = pcVar18;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    plVar10 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_88._8_8_;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    *(longlong *)auStack_88._0_8_ = *(longlong *)auStack_88._0_8_ + -1;
    if (*(longlong *)auStack_88._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_88._0_8_ + 8) + 0x30))();
    }
    if ((pcStack_78 != (code *)0x0) &&
       (*(longlong *)pcStack_78 = *(longlong *)pcStack_78 + -1, *(longlong *)pcStack_78 == 0)) {
      (**(code **)(*(longlong *)(pcStack_78 + 8) + 0x30))();
    }
    pcStack_78 = (code *)0x0;
    auStack_88 = (undefined1  [16])0x0;
    iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar8 != 0) {
      lVar9 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar9 + 0x1188) == 0) {
        plVar16 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar8 = *(int *)(lVar9 + 0x1188) + -1;
        *(int *)(lVar9 + 0x1188) = iVar8;
        plVar16 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar8 * 8);
        *plVar16 = 1;
      }
      plVar16[2] = 0;
      plVar16[4] = 0;
      lVar9 = *(longlong *)(pcStack_b8 + 0x1f8);
      plVar16[3] = 0;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar2 = plVar16[-1];
      puVar17 = *(undefined8 **)(lVar9 + 8);
      *puVar17 = plVar16 + -2;
      plVar16[-2] = lVar9;
      plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
      *(longlong **)(lVar9 + 8) = plVar16 + -2;
      plVar10 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar11;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
LAB_23e7e6cbe:
      plVar23 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar22 = (longlong *)0x0;
LAB_23e7e6ccc:
      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar12 = *(longlong **)(lVar9 + 0x28);
      plVar13 = (longlong *)plVar12[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
      *(undefined4 *)(plVar12 + 8) = 0xffffffff;
      if (plVar13 != (longlong *)0x0) {
        plVar12[2] = 0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12[0xf] = 0;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
        (**(code **)(plVar22[1] + 0x30))(plVar22);
      }
      if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if ((plStack_c8 != (longlong *)0x0) && (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0)) {
        (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
      }
      if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
        (**(code **)(plVar23[1] + 0x30))(plVar23);
      }
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return plVar16;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return plVar16;
    }
    pcVar19 = *(code **)(param_1 + 0x138);
    auStack_68._8_8_ = pcVar19;
    if ((pcVar19 == pcVar6) || (pcVar19 == (code *)0x0)) {
      plStack_b0 = *(longlong **)PyExc_RuntimeError_exref;
      pcStack_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar19 = *(code **)(param_1 + 0x138);
      *plStack_b0 = *plStack_b0 + 1;
      pcStack_58 = (code *)0x0;
      *(longlong **)(param_1 + 0x138) = plVar11;
      auStack_68 = (undefined1  [16])0x0;
      if (pcVar19 != (code *)0x0) {
        iVar8 = 0x66;
        goto LAB_23e7e7cfe;
      }
      auStack_68._8_8_ = pcStack_c0;
      auStack_68._0_8_ = plStack_b0;
    }
    else {
      plStack_b0 = *(longlong **)(pcVar19 + 8);
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      *plStack_b0 = *plStack_b0 + 1;
      auStack_68._0_8_ = plStack_b0;
      pcStack_58 = *(code **)(pcVar19 + 0x28);
      iVar8 = 0;
      pcStack_c0 = pcVar19;
      if (pcStack_58 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar11;
      }
      else {
        *(longlong *)pcStack_58 = *(longlong *)pcStack_58 + 1;
        if (*(longlong **)(pcStack_58 + 0x18) == plVar22) {
          *(undefined4 *)(plVar22 + 5) = *(undefined4 *)(pcStack_58 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar11;
      }
LAB_23e7e7cfe:
      pcVar18 = pcStack_58;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
      }
      auStack_68._8_8_ = pcStack_c0;
      auStack_68._0_8_ = plStack_b0;
      pcStack_58 = pcVar18;
      if (pcVar18 != (code *)0x0) {
        if (*(longlong **)(pcVar18 + 0x18) == plVar22) goto LAB_23e7e7910;
        if (iVar8 == 0) {
          uVar21 = (undefined4)plVar22[5];
          plVar23 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
        }
        else {
          plVar23 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          plStack_c8 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          uVar21 = 0x66;
        }
        goto LAB_23e7e77e0;
      }
      if (iVar8 == 0) {
        uVar21 = (undefined4)plVar22[5];
        plVar23 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plStack_c8 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e7e7f03;
      }
    }
    plVar23 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plStack_c8 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar21 = 0x66;
  }
  else {
    *(undefined4 *)(plVar22 + 5) = 0x67;
    plVar10 = (longlong *)FUN_23e939610(param_1,plVar16,lVar9 + 0x18);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if (plVar10 == (longlong *)0x0) goto LAB_23e7e73a0;
    lVar9 = *(longlong *)(param_1 + 0x10);
    if (*(int *)(lVar9 + 0x1188) == 0) {
      plVar16 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    }
    else {
      iVar8 = *(int *)(lVar9 + 0x1188) + -1;
      *(int *)(lVar9 + 0x1188) = iVar8;
      plVar16 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar8 * 8);
      *plVar16 = 1;
    }
    pcStack_b8 = _PyRuntime_exref;
    plVar16[2] = 0;
    plVar16[4] = 0;
    lVar9 = *(longlong *)(pcStack_b8 + 0x1f8);
    plVar16[3] = 0;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar2 = plVar16[-1];
    puVar17 = *(undefined8 **)(lVar9 + 8);
    *puVar17 = plVar16 + -2;
    plVar16[-2] = lVar9;
    plVar16[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar9 + 8) = plVar16 + -2;
    lVar9 = *(longlong *)(DAT_23eeddba8 + 0x20);
    if (*(char *)(lVar9 + 10) != '\0') {
      iVar8 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = DAT_23ec15618;
        iVar8 = DAT_23ec15618;
        DAT_23ec15618 = DAT_23ec15618 + 1;
      }
      if (_DAT_23ec155fc != iVar8) {
        _DAT_23ec155fc = iVar8;
        _DAT_23eedeb28 = FUN_23e8cbd60(lVar9,_DAT_23eeddd40,*(undefined8 *)(_DAT_23eeddd40 + 0x18));
      }
      if (-1 < _DAT_23eedeb28) {
        lVar2 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        lVar20 = *(longlong *)(lVar2 + 8 + _DAT_23eedeb28 * 0x10);
        if (lVar20 != 0) goto LAB_23e7e6f60;
        _DAT_23eedeb28 = FUN_23e8cbd60(lVar9,_DAT_23eeddd40,*(undefined8 *)(_DAT_23eeddd40 + 0x18));
        if (-1 < _DAT_23eedeb28) {
          lVar20 = *(longlong *)(lVar2 + 8 + _DAT_23eedeb28 * 0x10);
          goto LAB_23e7e7dce;
        }
      }
LAB_23e7e7de0:
      plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddd40);
      if ((plVar11 != (longlong *)0x0) && (lVar20 = *plVar11, lVar20 != 0)) goto LAB_23e7e6f60;
      FUN_23e915740(param_1,auStack_68,_DAT_23eeddd40);
      plStack_b0 = (longlong *)auStack_68._0_8_;
      pcStack_c0 = (code *)auStack_68._8_8_;
      if (pcStack_58 == (code *)0x0) {
        plStack_c8 = (longlong *)0x0;
        plVar23 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uVar21 = 0x6b;
        goto LAB_23e7e7f03;
      }
      if (*(longlong **)(pcStack_58 + 0x18) == plVar22) {
        plStack_c8 = (longlong *)0x0;
        plVar23 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        pcVar18 = pcStack_58;
        goto LAB_23e7e7930;
      }
LAB_23e7e7e6a:
      plVar23 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar21 = 0x6b;
      plStack_c8 = (longlong *)0x0;
LAB_23e7e77e0:
      pcVar6 = pcStack_58;
      pcVar18 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar22;
      *plVar22 = *plVar22 + 1;
      lVar9 = *(longlong *)(pcStack_b8 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar21;
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar2 = *(longlong *)(pcVar18 + -8);
      puVar17 = *(undefined8 **)(lVar9 + 8);
      *puVar17 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar9;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
      lVar2 = *(longlong *)pcVar6;
      *(code **)(lVar9 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar6;
      if (lVar2 == 0) {
        (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
      }
      goto LAB_23e7e7930;
    }
    plVar11 = (longlong *)FUN_23a37a020(DAT_23eeddba8,_DAT_23eeddd40);
    if (plVar11 == (longlong *)0x0) goto LAB_23e7e7de0;
    lVar20 = *plVar11;
LAB_23e7e7dce:
    if (lVar20 == 0) goto LAB_23e7e7de0;
LAB_23e7e6f60:
    *(undefined4 *)(plVar22 + 5) = 0x6b;
    plVar11 = (longlong *)FUN_23e915840(param_1,lVar20,_DAT_23eeddd48);
    if (plVar11 == (longlong *)0x0) {
      plStack_b0 = *(longlong **)(param_1 + 0x60);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_c0 = *(code **)(param_1 + 0x68);
      auStack_68._8_8_ = pcStack_c0;
      auStack_68._0_8_ = plStack_b0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar11 = (longlong *)0x0;
      if (pcVar18 != (code *)0x0) {
        if (plVar22 == *(longlong **)(pcVar18 + 0x18)) {
          plStack_c8 = (longlong *)0x0;
          plVar23 = (longlong *)0x0;
          goto LAB_23e7e7930;
        }
        plVar23 = (longlong *)0x0;
        uVar21 = 0x6b;
        plStack_c8 = (longlong *)0x0;
        pcStack_58 = pcVar18;
        goto LAB_23e7e77e0;
      }
      plVar23 = (longlong *)0x0;
      uVar21 = 0x6b;
      plStack_c8 = (longlong *)0x0;
      pcStack_58 = (code *)0x0;
    }
    else {
      plVar12 = (longlong *)FUN_23ebf7180(plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      plVar23 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_c8 = (longlong *)0x0;
      if (plVar12 == (longlong *)0x0) {
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        pcStack_58 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        auStack_68._8_8_ = pcStack_c0;
        auStack_68._0_8_ = plStack_b0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_58 != (code *)0x0) {
          if (*(longlong **)(pcStack_58 + 0x18) == plVar22) {
            plStack_c8 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            pcVar18 = pcStack_58;
            goto LAB_23e7e7930;
          }
          goto LAB_23e7e7e6a;
        }
        plVar11 = (longlong *)0x0;
        uVar21 = 0x6b;
        plStack_c8 = (longlong *)0x0;
        pcStack_58 = (code *)0x0;
      }
      else {
        do {
          pcVar18 = *(code **)(plVar12[1] + 0xe0);
          if (pcVar18 == (code *)0x0) {
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plVar12[1] + 0x18));
LAB_23e7e809c:
            cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar7 == '\0') {
              plStack_b0 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              pcStack_58 = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_c0 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              auStack_68 = (undefined1  [16])0x0;
              if (plVar11 != (longlong *)0x0) {
                uVar21 = 0x6b;
                goto LAB_23e7e7bd0;
              }
              plVar11 = (longlong *)0x0;
              uVar21 = 0x6b;
              goto LAB_23e7e7bfe;
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            lVar9 = *plVar12;
            *plVar12 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *plVar16 = *plVar16 + 1;
            plVar22 = plVar16;
            goto LAB_23e7e6ccc;
          }
          plVar13 = (longlong *)(*pcVar18)(plVar12);
          if (plVar13 == (longlong *)0x0) goto LAB_23e7e809c;
          if (plVar11 == (longlong *)0x0) {
            *plVar13 = *plVar13 + 1;
          }
          else {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              lVar9 = *plVar13;
            }
            else {
              lVar9 = *plVar13;
            }
            *plVar13 = lVar9 + 1;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
          }
          lVar9 = _DAT_23eeddd58;
          *(undefined4 *)(plVar22 + 5) = 0x6c;
          plVar14 = (longlong *)
                    FUN_23e915840(param_1,plVar13,_DAT_23eeddd50,*(undefined8 *)(lVar9 + 0x18));
          plVar11 = plVar13;
          if (plVar14 == (longlong *)0x0) {
LAB_23e7e8130:
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar21 = 0x6c;
            pcStack_c0 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7e7bd0;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eeddbf8);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23e7e8130;
          *(undefined4 *)(plVar22 + 5) = 0x6c;
          plVar14 = (longlong *)FUN_23e91a870(param_1,plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar14 == (longlong *)0x0) goto LAB_23e7e8130;
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eeddd60);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23e7e8130;
          *(undefined4 *)(plVar22 + 5) = 0x6c;
          plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar15,_DAT_23eeddd68);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar14 == (longlong *)0x0) goto LAB_23e7e8130;
          if ((plStack_c8 != (longlong *)0x0) && (*plStack_c8 = *plStack_c8 + -1, *plStack_c8 == 0))
          {
            (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
          }
          lVar9 = _DAT_23eeddd70;
          *(undefined4 *)(plVar22 + 5) = 0x6d;
          plVar13 = (longlong *)
                    FUN_23e915840(param_1,plVar13,_DAT_23eeddd50,*(undefined8 *)(lVar9 + 0x18));
          plStack_c8 = plVar14;
          if (plVar13 == (longlong *)0x0) {
LAB_23e7e82b0:
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            uVar21 = 0x6d;
            pcStack_c0 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7e7bd0;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eeddd78);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23e7e82b0;
          *(undefined4 *)(plVar22 + 5) = 0x6d;
          plVar13 = (longlong *)FUN_23e9557e0(param_1,plVar15,_DAT_23eeddd80);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar13 == (longlong *)0x0) goto LAB_23e7e82b0;
          if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
            (**(code **)(plVar23[1] + 0x30))(plVar23);
          }
          lVar9 = FUN_23e8ddb70();
          uVar3 = _DAT_23eeddd98;
          plVar23 = plVar13;
          if (lVar9 == 0) {
            FUN_23e915740(param_1,auStack_68,_DAT_23eeddd88);
            uVar21 = 0x6e;
            plStack_b0 = (longlong *)auStack_68._0_8_;
            pcStack_c0 = (code *)auStack_68._8_8_;
            pcVar18 = pcStack_58;
            goto LAB_23e7e7bd0;
          }
          *(undefined4 *)(plVar22 + 5) = 0x6e;
          auStack_88._8_8_ = plVar14;
          auStack_88._0_8_ = uVar3;
          plVar15 = (longlong *)FUN_23e954670(param_1,lVar9,_DAT_23eeddd90,auStack_88);
          if (plVar15 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            pcStack_c0 = *(code **)(param_1 + 0x68);
            uVar21 = 0x6e;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7e7bd0;
          }
          iVar8 = FUN_23a35f020(plVar15);
          lVar9 = *plVar15 + -1;
          if (iVar8 == -1) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_c0 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar15 = lVar9;
            if (lVar9 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            uVar21 = 0x6e;
            goto LAB_23e7e7bd0;
          }
          *plVar15 = lVar9;
          if (lVar9 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (iVar8 != 0) {
            lVar9 = *(longlong *)(param_1 + 0x10);
            puVar17 = *(undefined8 **)(lVar9 + 0xe20);
            if (puVar17 == (undefined8 *)0x0) {
              puVar17 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              uVar3 = puVar17[3];
              *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
              *(undefined8 *)(lVar9 + 0xe20) = uVar3;
              *puVar17 = 1;
            }
            lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_b8 + 0x1f8) + 0x10) + 0x2e8);
            uVar3 = puVar17[-1];
            puVar4 = *(undefined8 **)(lVar9 + 8);
            *puVar4 = puVar17 + -2;
            puVar17[-2] = lVar9;
            puVar17[-1] = (ulonglong)((uint)uVar3 & 3) | (ulonglong)puVar4;
            *(undefined8 **)(lVar9 + 8) = puVar17 + -2;
            *plVar14 = *plVar14 + 1;
            puVar17[3] = plVar14;
            *plVar13 = *plVar13 + 1;
            puVar17[4] = plVar13;
            FUN_23e8ba4b0(plVar16);
          }
          lVar9 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar9 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
             (plStack_b0 = *(longlong **)(param_1 + 0x60), plStack_b0 != (longlong *)0x0))
          goto LAB_23e7e7ba6;
          if (*(int *)(lVar9 + 0x68) == 0) {
            plVar13 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar13 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar13 == (longlong *)0x0);
        plVar14 = *(longlong **)(param_1 + 0x60);
        plVar15 = *(longlong **)(param_1 + 0x70);
        plVar5 = *(longlong **)(param_1 + 0x68);
        *(longlong **)(param_1 + 0x60) = plVar13;
        *(undefined8 *)(param_1 + 0x90) = 0;
        *plVar13 = *plVar13 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        if ((plVar15 == (longlong *)0x0) || (*plVar15 = *plVar15 + -1, *plVar15 != 0)) {
          plStack_b0 = *(longlong **)(param_1 + 0x60);
        }
        else {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
          plStack_b0 = *(longlong **)(param_1 + 0x60);
        }
LAB_23e7e7ba6:
        pcStack_c0 = *(code **)(param_1 + 0x68);
        pcVar18 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar21 = 0x6b;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7e7bd0:
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_23e7e7bfe:
        lVar9 = *plVar12;
        *plVar12 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        auStack_68._8_8_ = pcStack_c0;
        auStack_68._0_8_ = plStack_b0;
        pcStack_58 = pcVar18;
        if (pcVar18 != (code *)0x0) {
          if (plVar22 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23e7e7930;
          goto LAB_23e7e77e0;
        }
      }
    }
  }
LAB_23e7e7f03:
  pcVar18 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar6 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar6;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar18 + 0x10) = 0;
  *(longlong **)(pcVar18 + 0x18) = plVar22;
  *plVar22 = *plVar22 + 1;
  lVar9 = *(longlong *)(pcStack_b8 + 0x1f8);
  *(undefined4 *)(pcVar18 + 0x24) = uVar21;
  lVar9 = *(longlong *)(lVar9 + 0x10);
  *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
  lVar9 = *(longlong *)(lVar9 + 0x2e8);
  lVar2 = *(longlong *)(pcVar18 + -8);
  puVar17 = *(undefined8 **)(lVar9 + 8);
  *puVar17 = pcVar18 + -0x10;
  *(longlong *)(pcVar18 + -0x10) = lVar9;
  *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar17;
  *(code **)(lVar9 + 8) = pcVar18 + -0x10;
LAB_23e7e7930:
  pcStack_58 = pcVar18;
  pcVar18 = pcStack_58;
  FUN_23e8bba40(plVar22,"oooooo",plVar1,plVar10,plVar16,plVar11,plStack_c8,plVar23);
  if (_DAT_23eedeb38 == plVar22) {
    *plVar22 = *plVar22 + -1;
    if (*plVar22 == 0) {
      (**(code **)(plVar22[1] + 0x30))(plVar22);
    }
    _DAT_23eedeb38 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar22 = *(longlong **)(lVar9 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  plVar12 = (longlong *)plVar22[2];
  *(undefined4 *)(plVar22 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar22[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar22 = *plVar22 + -1;
  if (*plVar22 == 0) {
    (**(code **)(plVar22[1] + 0x30))(plVar22);
  }
  plVar22[0xf] = 0;
  pcStack_58 = (code *)0x0;
  auStack_68 = (undefined1  [16])0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar9 = *plStack_c8, *plStack_c8 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
  }
  if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
    (**(code **)(plVar23[1] + 0x30))(plVar23);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plStack_b0,pcStack_c0,pcVar18);
  return (longlong *)0x0;
}
