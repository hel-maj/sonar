/* ===== 23c035230 config_manager:84 ===== */
/* ghidra_name=FUN_23c035230 entry=23c035230 size=3928 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23c035230(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined8 uVar4;
  char cVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  int iVar15;
  longlong lVar16;
  longlong *plVar17;
  undefined4 uVar18;
  longlong *plVar19;
  undefined8 uVar20;
  longlong *plStack_b0;
  undefined8 uStack_88;
  longlong *plStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar6 = _DAT_23ee0b620;
  param_3 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23ee0b620 == (longlong *)0x0) {
LAB_23c03528f:
    _DAT_23ee0b620 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee0b618,DAT_23ee0b670,0x18);
  }
  else {
    lVar13 = *_DAT_23ee0b620;
    if (1 < lVar13) {
      *_DAT_23ee0b620 = lVar13 + -1;
      goto LAB_23c03528f;
    }
    if (_DAT_23ee0b620[2] != 0) {
      *_DAT_23ee0b620 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23c03528f;
    }
  }
  plVar3 = _DAT_23ee0b620;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23ee0b620 + 9;
  lVar16 = *(longlong *)(lVar13 + 8);
  _DAT_23ee0b620[0xf] = lVar16;
  *(longlong **)(lVar13 + 8) = plVar6;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar20 = _DAT_23ee07638;
  *(undefined4 *)(plVar3 + 5) = 0x56;
  plVar6 = (longlong *)FUN_23e91bfe0(param_1,param_3,uVar20);
  if (plVar6 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x56;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23c035d5b;
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23ed6ce40);
  uVar20 = DAT_23ee075d8;
  lVar13 = DAT_23ed6cce8;
  if (plVar7 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x57;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_b0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23c035d5b;
  }
  lVar16 = *(longlong *)(param_1 + 0x10);
  plVar8 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  iVar15 = *(int *)(lVar16 + 0x1410);
  *plVar8 = *plVar8 + 1;
  if (iVar15 == 0) {
    plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar8 = *(longlong **)(lVar13 + 0x20);
  }
  else {
    iVar15 = iVar15 + -1;
    *(int *)(lVar16 + 0x1410) = iVar15;
    plVar14 = *(longlong **)(lVar16 + 0x1190 + (longlong)iVar15 * 8);
    *plVar14 = 1;
  }
  lVar13 = *(longlong *)(lVar13 + 0x28);
  plVar14[4] = (longlong)plVar8;
  plVar14[5] = lVar13;
  plVar14[2] = 0;
  plVar14[3] = 1;
  *(undefined4 *)(plVar3 + 5) = 0x57;
  uStack_88 = uVar20;
  plStack_80 = plVar14;
  plStack_b0 = (longlong *)FUN_23e94ed00(param_1,plVar7,&uStack_88);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if (plStack_b0 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x57;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23c035d5b;
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(plStack_b0,_DAT_23ee07640);
  if (plVar7 == (longlong *)0x0) {
LAB_23c035d30:
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar13 = *(longlong *)(param_1 + 0x60);
    uVar20 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x58;
    plVar8 = (longlong *)FUN_23e91a870(param_1,plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 == (longlong *)0x0) goto LAB_23c035d30;
    plVar7 = (longlong *)FUN_23ebf7180(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23c035d30;
    lVar13 = *(longlong *)(param_1 + 0x10);
    if (*(int *)(lVar13 + 0x1188) == 0) {
      plVar8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    }
    else {
      iVar15 = *(int *)(lVar13 + 0x1188) + -1;
      *(int *)(lVar13 + 0x1188) = iVar15;
      plVar8 = *(longlong **)(lVar13 + 0xf08 + (longlong)iVar15 * 8);
      *plVar8 = 1;
    }
    pcVar2 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[4] = 0;
    lVar13 = *(longlong *)(pcVar2 + 0x1f8);
    plVar8[3] = 0;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar16 = plVar8[-1];
    puVar1 = *(undefined8 **)(lVar13 + 8);
    *puVar1 = plVar8 + -2;
    plVar8[-2] = lVar13;
    plVar8[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar13 + 8) = plVar8 + -2;
    plVar14 = (longlong *)0x0;
    plVar19 = (longlong *)0x0;
    plVar17 = (longlong *)0x0;
    do {
      pcVar2 = *(code **)(plVar7[1] + 0xe0);
      if (pcVar2 == (code *)0x0) {
        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                     *(undefined8 *)(plVar7[1] + 0x18));
LAB_23c035a0d:
        cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar5 != '\0') {
          *plVar8 = *plVar8 + 1;
          lVar13 = *plVar7;
          *plVar7 = lVar13 + -1;
          if (lVar13 + -1 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar3 = *(longlong **)(lVar13 + 0x28);
          plVar7 = (longlong *)plVar3[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
          *(undefined4 *)(plVar3 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar3[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))(plVar3);
          }
          plVar3[0xf] = 0;
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          lVar13 = *plStack_b0;
          *plStack_b0 = lVar13 + -1;
          if (lVar13 + -1 == 0) {
            (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
          }
          lVar13 = *param_3;
          *param_3 = lVar13 + -1;
          if (lVar13 + -1 != 0) {
            return plVar8;
          }
          (**(code **)(param_3[1] + 0x30))(param_3);
          return plVar8;
        }
        lVar13 = *(longlong *)(param_1 + 0x60);
        uVar20 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c0357cb;
      }
      plVar9 = (longlong *)(*pcVar2)(plVar7);
      if (plVar9 == (longlong *)0x0) goto LAB_23c035a0d;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      plVar10 = (longlong *)FUN_23a388310(plVar9);
      plVar17 = plVar9;
      if (plVar10 == (longlong *)0x0) {
        lVar13 = *(longlong *)(param_1 + 0x60);
        uVar20 = *(undefined8 *)(param_1 + 0x68);
        plVar9 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c0357cb;
      }
      plVar11 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
      if ((plVar11 == (longlong *)0x0) &&
         (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar11 == (longlong *)0x0))
      {
        plVar12 = (longlong *)0x0;
        *plVar10 = *plVar10 + -1;
        plVar9 = plStack_68;
        lVar13 = auStack_78._0_8_;
        uVar20 = auStack_78._8_8_;
        if (*plVar10 == 0) {
LAB_23c035c0c:
          plVar9 = plStack_68;
          (**(code **)(plVar10[1] + 0x30))(plVar10);
          auStack_78 = (undefined1  [16])0x0;
          plStack_68 = (longlong *)0x0;
          if (plVar11 != (longlong *)0x0) {
LAB_23c035c4e:
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
          }
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
        }
        goto LAB_23c0357cb;
      }
      plVar12 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
      if ((plVar12 == (longlong *)0x0) &&
         (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2), plVar12 == (longlong *)0x0))
      {
        lVar16 = *plVar10;
LAB_23c035cf5:
        *plVar10 = lVar16 + -1;
        plVar9 = plStack_68;
        lVar13 = auStack_78._0_8_;
        uVar20 = auStack_78._8_8_;
        if (lVar16 + -1 == 0) goto LAB_23c035c0c;
        goto LAB_23c035c4e;
      }
      cVar5 = FUN_23a3884a0(param_1,auStack_78,plVar10,2);
      lVar16 = *plVar10;
      if (cVar5 == '\0') goto LAB_23c035cf5;
      *plVar10 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      lVar13 = *plVar11;
      *plVar11 = lVar13 + 1;
      if (plVar14 != (longlong *)0x0) {
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar13 = *plVar11 + -1;
      }
      *plVar11 = lVar13;
      if (lVar13 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      lVar13 = *plVar12;
      *plVar12 = lVar13 + 1;
      if (plVar19 != (longlong *)0x0) {
        *plVar19 = *plVar19 + -1;
        if (*plVar19 == 0) {
          (**(code **)(plVar19[1] + 0x30))(plVar19);
        }
        lVar13 = *plVar12 + -1;
      }
      *plVar12 = lVar13;
      if (lVar13 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      iVar15 = FUN_23a35f020(plVar12);
      plVar14 = plVar11;
      plVar19 = plVar12;
      if ((iVar15 == -1) ||
         ((iVar15 != 0 && (cVar5 = FUN_23e8bc550(plVar8,plVar11), cVar5 == '\0')))) {
        lVar13 = *(longlong *)(param_1 + 0x60);
        uVar20 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23c0357b1;
      }
      lVar16 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar16 + 0x28) + 0x160) != 0) || (*(int *)(lVar16 + 0x78) != 0))
          && (iVar15 = Py_MakePendingCalls(), iVar15 < 0)) &&
         (lVar13 = *(longlong *)(param_1 + 0x60), lVar13 != 0)) goto LAB_23c0359cc;
      if (*(int *)(lVar16 + 0x68) == 0) {
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
    } while (plVar9 == (longlong *)0x0);
    plVar10 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar12 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar9;
    *plVar9 = *plVar9 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((plVar12 == (longlong *)0x0) || (*plVar12 = *plVar12 + -1, *plVar12 != 0)) {
      lVar13 = *(longlong *)(param_1 + 0x60);
    }
    else {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      lVar13 = *(longlong *)(param_1 + 0x60);
    }
LAB_23c0359cc:
    uVar20 = *(undefined8 *)(param_1 + 0x68);
LAB_23c0357b1:
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c0357cb:
    plStack_68 = (longlong *)0x0;
    auStack_78 = (undefined1  [16])0x0;
    lVar16 = *plVar7;
    *plVar7 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    plStack_68 = (longlong *)0x0;
    auStack_78 = (undefined1  [16])0x0;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
  }
  uVar18 = 0x58;
  auStack_78._8_8_ = uVar20;
  auStack_78._0_8_ = lVar13;
  plStack_68 = plVar9;
LAB_23c035d5b:
  plVar8 = plStack_68;
  plVar7 = DAT_23ed6a4f8;
  if (plStack_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar2 = _PyRuntime_exref;
    plVar7[2] = 0;
    plVar7[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar13 = *(longlong *)(pcVar2 + 0x1f8);
    *(undefined4 *)(plVar7 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar18;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar16 = plVar7[-1];
    puVar1 = *(undefined8 **)(lVar13 + 8);
    *puVar1 = plVar7 + -2;
    plVar7[-2] = lVar13;
    plVar7[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar13 + 8) = plVar7 + -2;
    plVar14 = plVar7;
  }
  else {
    plVar14 = plStack_68;
    if ((longlong *)plStack_68[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar2 = _PyRuntime_exref;
      plVar7[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar13 = *(longlong *)(pcVar2 + 0x1f8);
      *(undefined4 *)(plVar7 + 4) = 0xffffffff;
      *(undefined4 *)((longlong)plVar7 + 0x24) = uVar18;
      lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
      lVar16 = plVar7[-1];
      puVar1 = *(undefined8 **)(lVar13 + 8);
      *puVar1 = plVar7 + -2;
      plVar7[-2] = lVar13;
      plVar7[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar1;
      lVar16 = *plVar8;
      *(longlong **)(lVar13 + 8) = plVar7 + -2;
      plVar7[2] = (longlong)plVar8;
      plVar14 = plVar7;
      if (lVar16 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  plStack_68 = plVar14;
  FUN_23e8bba40(plVar3,&DAT_23ec43865,param_3,plVar6,plStack_b0);
  if (_DAT_23ee0b620 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee0b620 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar13 + 0x28);
  plVar7 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar7 = plStack_68;
  plVar3[0xf] = 0;
  uVar4 = auStack_78._8_8_;
  uVar20 = auStack_78._0_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar13 = *plStack_b0, *plStack_b0 = lVar13 + -1, lVar13 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))();
  }
  lVar13 = *param_3;
  *param_3 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,uVar20,uVar4,plVar7);
  return (longlong *)0x0;
}
