/* ===== 23e88c3c0 workers.fishing.store_fish:198 ===== */
/* ghidra_name=FUN_23e88c3c0 entry=23e88c3c0 size=11220 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e88c3c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  longlong lVar12;
  code *pcVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  longlong lVar21;
  longlong lVar22;
  code *pcVar23;
  longlong lVar24;
  longlong lVar25;
  code *pcVar26;
  bool bVar27;
  longlong *plStack_e0;
  code *pcStack_d8;
  code *pcStack_c0;
  longlong *plStack_98;
  undefined8 uStack_90;
  undefined1 auStack_88 [16];
  longlong *aplStack_78 [7];
  
  plVar8 = _DAT_23eede650;
  plVar1 = (longlong *)*param_3;
  aplStack_78[0] = (longlong *)0x0;
  auStack_88._0_8_ = (code *)0x0;
  auStack_88._8_8_ = 0;
  if (_DAT_23eede650 == (longlong *)0x0) {
LAB_23e88c425:
    _DAT_23eede650 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede648,DAT_23eede708,0x30);
  }
  else {
    lVar12 = *_DAT_23eede650;
    if (1 < lVar12) {
      *_DAT_23eede650 = lVar12 + -1;
      goto LAB_23e88c425;
    }
    if (_DAT_23eede650[2] != 0) {
      *_DAT_23eede650 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e88c425;
    }
  }
  plVar3 = _DAT_23eede650;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eede650 + 9;
  lVar22 = *(longlong *)(lVar12 + 8);
  _DAT_23eede650[0xf] = lVar22;
  *(longlong **)(lVar12 + 8) = plVar8;
  if ((lVar22 != 0) &&
     (((*(char *)(lVar22 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar22 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar22 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar22 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar22 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar11 = _DAT_23eedca40;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
  if (plVar8 == (longlong *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x70);
    pcVar13 = *(code **)(param_1 + 0x60);
    pcVar26 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 200;
    pcStack_d8 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e88d3a6;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedcaa0);
  if (plVar9 == (longlong *)0x0) {
    auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar8 = *plVar8 + -1;
    plVar10 = (longlong *)0x0;
    if (*plVar8 == 0) {
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      pcStack_d8 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      uVar18 = 200;
      plVar8 = aplStack_78[0];
      pcVar13 = (code *)auStack_88._0_8_;
      uVar11 = auStack_88._8_8_;
    }
    else {
      pcStack_d8 = (code *)0x0;
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      uVar18 = 200;
      plStack_e0 = (longlong *)0x0;
      plVar8 = aplStack_78[0];
      pcVar13 = (code *)auStack_88._0_8_;
      uVar11 = auStack_88._8_8_;
    }
    goto LAB_23e88d3a6;
  }
  plStack_e0 = (longlong *)FUN_23e8c6f80(plVar8,plVar9);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
    if (plStack_e0 == (longlong *)0x0) goto LAB_23e88c85e;
LAB_23e88c524:
    *(undefined4 *)(plVar3 + 5) = 0xca;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plStack_e0,DAT_23ed6cee0);
    if (plVar10 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xca;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    iVar7 = FUN_23a35f020(plVar10);
    *plVar10 = *plVar10 + -1;
    plVar8 = plVar10;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      plVar8 = plVar10;
    }
    if (iVar7 == -1) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xca;
      plVar10 = (longlong *)0x0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    if (iVar7 == 0) {
      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar9 = _DAT_23eedcb38;
      lVar12 = *(longlong *)(param_1 + 0x10);
      plVar17 = *(longlong **)(lVar12 + 0xe20);
      if (plVar17 == (longlong *)0x0) {
        plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar22 = plVar17[3];
        *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
        *(longlong *)(lVar12 + 0xe20) = lVar22;
        *plVar17 = 1;
      }
      pcVar13 = _PyRuntime_exref;
      plVar17[4] = 0;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
      lVar22 = plVar17[-1];
      puVar2 = *(undefined8 **)(lVar12 + 8);
      *puVar2 = plVar17 + -2;
      plVar17[-2] = lVar12;
      plVar17[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar12 + 8) = plVar17 + -2;
      *plVar9 = *plVar9 + 1;
      plVar17[3] = (longlong)plVar9;
      uVar4 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar9 == (longlong *)0x0) goto LAB_23e88dc04;
        *plVar9 = *plVar9 + 1;
        DAT_23ed6a4c0 = plVar9;
      }
      uStack_90 = uVar4;
      plStack_98 = plStack_e0;
      lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
      if (lVar12 == 0) {
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar17 = *plVar17 + -1;
        plVar10 = (longlong *)0x0;
        if (*plVar17 == 0) {
          plVar9 = (longlong *)0x0;
          pcVar26 = (code *)0x0;
          (**(code **)(plVar17[1] + 0x30))(plVar17);
          pcStack_d8 = (code *)0x0;
          uVar18 = 0xcb;
          plVar8 = aplStack_78[0];
          pcVar13 = (code *)auStack_88._0_8_;
          uVar11 = auStack_88._8_8_;
        }
        else {
          pcStack_d8 = (code *)0x0;
          pcVar26 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          uVar18 = 0xcb;
          plVar8 = aplStack_78[0];
          pcVar13 = (code *)auStack_88._0_8_;
          uVar11 = auStack_88._8_8_;
        }
      }
      else {
        plVar17[4] = lVar12;
        plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0xcb;
          plVar9 = (longlong *)FUN_23e914090(param_1,uVar11,plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar9 == (longlong *)0x0) {
            pcVar13 = *(code **)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            pcVar26 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0xcb;
            pcStack_d8 = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
            uVar11 = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e88d3a6;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          pcVar26 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          pcStack_d8 = (code *)0x0;
          lVar12 = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e88c711:
          pcVar13 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = lVar12;
          lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar8 = *(longlong **)(lVar12 + 0x28);
          plVar3 = (longlong *)plVar8[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
          *(undefined4 *)(plVar8 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar8[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8[0xf] = 0;
          lVar12 = *plStack_e0;
          *plStack_e0 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
          }
          if (plVar10 != (longlong *)0x0) {
LAB_23e88c7a8:
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
LAB_23e88c7ae:
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
          }
          if (plVar9 == (longlong *)0x0) goto LAB_23e88c7ce;
LAB_23e88c7bd:
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
LAB_23e88c7ce:
          if ((pcVar26 != (code *)0x0) &&
             (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
            (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
          }
          if ((pcStack_d8 != (code *)0x0) &&
             (lVar12 = *(longlong *)pcStack_d8, *(longlong *)pcStack_d8 = lVar12 + -1,
             lVar12 + -1 == 0)) {
            (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 != 0) {
            return pcVar13;
          }
          (**(code **)(plVar1[1] + 0x30))(plVar1);
          return pcVar13;
        }
        pcVar13 = *(code **)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        pcVar26 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0xcb;
        pcStack_d8 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        uVar11 = *(undefined8 *)(param_1 + 0x68);
      }
      goto LAB_23e88d3a6;
    }
    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar9 = _DAT_23eedcb40;
    lVar12 = *(longlong *)(param_1 + 0x10);
    plVar17 = *(longlong **)(lVar12 + 0xe20);
    if (plVar17 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar22 = plVar17[3];
      *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
      *(longlong *)(lVar12 + 0xe20) = lVar22;
      *plVar17 = 1;
    }
    pcVar13 = _PyRuntime_exref;
    plVar17[4] = 0;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
    lVar22 = plVar17[-1];
    puVar2 = *(undefined8 **)(lVar12 + 8);
    *puVar2 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar10 = DAT_23ed6a4c0;
    *plVar9 = *plVar9 + 1;
    plVar17[3] = (longlong)plVar9;
    uVar4 = DAT_23ed6cd28;
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + 1;
        DAT_23ed6a4c0 = plVar10;
        goto LAB_23e88ca50;
      }
LAB_23e88dc04:
      PyErr_PrintEx(0,0);
      Py_Exit(1);
      plVar10 = plVar8;
LAB_23e88dc17:
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xd6;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
LAB_23e88ca50:
    uStack_90 = uVar4;
    plStack_98 = plStack_e0;
    lVar12 = FUN_23e94ed00(param_1,plVar10,&plStack_98);
    if (lVar12 == 0) {
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar17 = *plVar17 + -1;
      plVar10 = (longlong *)0x0;
      if (*plVar17 == 0) {
        pcVar26 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        (**(code **)(plVar17[1] + 0x30))(plVar17);
        pcStack_d8 = (code *)0x0;
        uVar18 = 0xce;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      else {
        pcStack_d8 = (code *)0x0;
        pcVar26 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        uVar18 = 0xce;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      goto LAB_23e88d3a6;
    }
    plVar17[4] = lVar12;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    if (plVar8 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xce;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *(undefined4 *)(plVar3 + 5) = 0xce;
    plVar9 = (longlong *)FUN_23e914090(param_1,uVar11,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xce;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar10 = (longlong *)FUN_23e8c6f80(plStack_e0,_DAT_23eedcb48);
    if (plVar10 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xd1;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *(undefined4 *)(plVar3 + 5) = 0xd2;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed6cee0);
    if (plVar8 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      uVar18 = 0xd2;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    iVar7 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar7 == -1) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xd2;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    if (iVar7 == 0) {
      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar3 + 5) = 0xd3;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcb50);
      if (plVar8 != (longlong *)0x0) {
LAB_23e88d8f6:
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        pcVar26 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        pcStack_d8 = (code *)0x0;
        lVar12 = *(longlong *)_Py_FalseStruct_exref + 1;
        goto LAB_23e88c711;
      }
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      uVar18 = 0xd3;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    lVar12 = FUN_23e8dbcd0();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,auStack_88,_DAT_23eedc940);
LAB_23e88dd85:
      plVar9 = (longlong *)0x0;
      pcVar26 = (code *)0x0;
      uVar18 = 0xd6;
      pcStack_d8 = (code *)0x0;
      plVar8 = aplStack_78[0];
      pcVar13 = (code *)auStack_88._0_8_;
      uVar11 = auStack_88._8_8_;
      goto LAB_23e88d3a6;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedcb58);
    if (plVar8 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      uVar18 = 0xd6;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar26 = (code *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    plVar9 = (longlong *)FUN_23e8bd350(plVar10);
    if (plVar9 == (longlong *)0x0) {
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      plVar9 = (longlong *)0x0;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        goto LAB_23e88dd85;
      }
      pcStack_d8 = (code *)0x0;
      pcVar26 = (code *)0x0;
      uVar18 = 0xd6;
      plVar8 = aplStack_78[0];
      pcVar13 = (code *)auStack_88._0_8_;
      uVar11 = auStack_88._8_8_;
      goto LAB_23e88d3a6;
    }
    *(undefined4 *)(plVar3 + 5) = 0xd6;
    plVar17 = (longlong *)FUN_23e914090(param_1,plVar8,plVar9);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar17 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xd6;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcStack_d8 = (code *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eedca30,plVar17);
    lVar12 = *plVar17;
    *plVar17 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    if (cVar6 == '\0') goto LAB_23e88dc17;
    pcVar13 = (code *)FUN_23e8bc2f0(plVar1,_DAT_23eedca30);
    if (pcVar13 == (code *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      uVar18 = 0xd7;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
    if (*(longlong *)pcVar13 == 0) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
    }
    pcVar5 = _Py_NoneStruct_exref;
    if (pcVar13 == _Py_NoneStruct_exref) {
      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar3 + 5) = 0xd8;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcb60);
      if (plVar8 != (longlong *)0x0) goto LAB_23e88d8f6;
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xd8;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar8 = _DAT_23eedcb68;
    lVar12 = *(longlong *)(param_1 + 0x10);
    plVar17 = *(longlong **)(lVar12 + 0xe20);
    if (plVar17 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar22 = plVar17[3];
      *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
      *(longlong *)(lVar12 + 0xe20) = lVar22;
      *plVar17 = 1;
    }
    pcVar13 = _PyRuntime_exref;
    plVar17[4] = 0;
    lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
    lVar22 = plVar17[-1];
    puVar2 = *(undefined8 **)(lVar12 + 8);
    *puVar2 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    uVar4 = _DAT_23eedca30;
    *plVar8 = *plVar8 + 1;
    plVar17[3] = (longlong)plVar8;
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar4);
    if (plVar8 == (longlong *)0x0) {
LAB_23e88dcd7:
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        plVar9 = (longlong *)0x0;
        pcVar26 = (code *)0x0;
        (**(code **)(plVar17[1] + 0x30))(plVar17);
        pcStack_d8 = (code *)0x0;
        uVar18 = 0xdb;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      else {
        pcStack_d8 = (code *)0x0;
        uVar18 = 0xdb;
        pcVar26 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      goto LAB_23e88d3a6;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eedc938);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e88dcd7;
    plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar9,_DAT_23eedcb70);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar4 = DAT_23ed6cd28;
    if (plVar14 == (longlong *)0x0) goto LAB_23e88dcd7;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar8 = plVar10;
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) goto LAB_23e88dc04;
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    uStack_90 = uVar4;
    plStack_98 = plVar14;
    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (lVar12 == 0) goto LAB_23e88dcd7;
    plVar17[4] = lVar12;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    if (plVar8 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xdb;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *(undefined4 *)(plVar3 + 5) = 0xdb;
    plVar9 = (longlong *)FUN_23e914090(param_1,uVar11,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xdb;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar26 = (code *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar11 = _DAT_23eedcb78;
    plVar9 = DAT_23ed6ccf0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
    *(undefined4 *)(plVar3 + 5) = 0xdf;
    plVar8 = (longlong *)FUN_23e915840(param_1,plStack_e0,uVar11);
    if (plVar8 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar18 = 0xdf;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar26 = (code *)0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    plVar17 = (longlong *)FUN_23ebf7180(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar17 == (longlong *)0x0) {
      pcVar13 = *(code **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x70);
      pcVar26 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0xdf;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e88d3a6;
    }
    lVar12 = plVar17[1];
    pcVar13 = *(code **)(lVar12 + 0xe0);
    if (pcVar13 == (code *)0x0) {
      pcVar26 = (code *)0x0;
      pcStack_d8 = (code *)0x0;
LAB_23e88df59:
      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                   *(undefined8 *)(lVar12 + 0x18));
      pcVar23 = pcVar26;
    }
    else {
      plVar8 = plVar9;
      if (plVar1 == (longlong *)0x0) {
        pcStack_d8 = (code *)0x0;
        pcVar23 = pcStack_d8;
        do {
          pcVar26 = (code *)(*pcVar13)(plVar17);
          if (pcVar26 == (code *)0x0) goto LAB_23e88df7e;
          if (pcVar23 == (code *)0x0) {
            *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
          }
          else {
            *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
            if (*(longlong *)pcVar23 == 0) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              lVar12 = *(longlong *)pcVar26;
            }
            else {
              lVar12 = *(longlong *)pcVar26;
            }
            *(longlong *)pcVar26 = lVar12 + 1;
            *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
            if (*(longlong *)pcVar23 == 0) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
            }
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(pcVar26,DAT_23ed6ce48);
          if (plVar14 == (longlong *)0x0) goto LAB_23e88e378;
          iVar7 = FUN_23e913250(plVar14,_DAT_23eedcb48);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar7 == -1) goto LAB_23e88e378;
          if (iVar7 != 1) {
            lVar12 = FUN_23e8dbcd0();
            if (lVar12 == 0) goto LAB_23e88e213;
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedcb58);
            if (plVar14 == (longlong *)0x0) goto LAB_23e88e620;
            plVar15 = (longlong *)FUN_23e8bd350(pcVar26);
            if (plVar15 == (longlong *)0x0) goto LAB_23e88e894;
            *(undefined4 *)(plVar3 + 5) = 0xe3;
            pcStack_c0 = (code *)FUN_23e914090(param_1,plVar14,plVar15);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (pcStack_c0 == (code *)0x0) goto LAB_23e88e620;
            if ((pcStack_d8 != (code *)0x0) &&
               (*(longlong *)pcStack_d8 = *(longlong *)pcStack_d8 + -1, *(longlong *)pcStack_d8 == 0
               )) {
              (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
            }
            if (pcStack_c0 != pcVar5) {
              FUN_23e8ba2b0(auStack_88,DAT_23eedc830);
              if (((code *)auStack_88._0_8_ != (code *)0x0) && ((code *)auStack_88._0_8_ != pcVar5))
              {
                FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8);
              }
              FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_88._8_8_);
              uVar18 = 0xe5;
              plVar8 = aplStack_78[0];
              pcVar13 = (code *)auStack_88._0_8_;
              uVar11 = auStack_88._8_8_;
              goto LAB_23e88e26b;
            }
            lVar12 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar12 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
               (*(longlong *)(param_1 + 0x60) != 0)) {
              pcStack_c0 = pcVar5;
              goto LAB_23e88e52d;
            }
            if (*(int *)(lVar12 + 0x68) != 0) {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
            }
            plVar14 = *(longlong **)(param_1 + 0x90);
            pcStack_d8 = pcVar5;
            if (plVar14 != (longlong *)0x0) {
              pcStack_c0 = pcVar5;
              goto LAB_23e88e4ab;
            }
          }
          lVar12 = plVar17[1];
          pcVar13 = *(code **)(lVar12 + 0xe0);
          pcVar23 = pcVar26;
        } while (pcVar13 != (code *)0x0);
        goto LAB_23e88df59;
      }
      pcVar13 = (code *)(*pcVar13)();
      if (pcVar13 != (code *)0x0) {
        *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
        pcStack_d8 = (code *)0x0;
        while (pcVar26 = pcVar13, plVar14 = (longlong *)FUN_23e8bc2f0(pcVar26,DAT_23ed6ce48),
              plVar9 = plVar8, plVar14 != (longlong *)0x0) {
          iVar7 = FUN_23e913250(plVar14,_DAT_23eedcb48);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar7 == -1) break;
          pcStack_c0 = pcStack_d8;
          if (iVar7 != 1) {
            lVar12 = FUN_23e8dbcd0();
            if (lVar12 == 0) goto LAB_23e88e213;
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedcb58);
            if (plVar14 == (longlong *)0x0) goto LAB_23e88e620;
            plVar15 = (longlong *)FUN_23e8bd350(pcVar26);
            if (plVar15 == (longlong *)0x0) goto LAB_23e88e894;
            *(undefined4 *)(plVar3 + 5) = 0xe3;
            pcStack_c0 = (code *)FUN_23e914090(param_1,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (pcStack_c0 == (code *)0x0) goto LAB_23e88e620;
            if ((pcStack_d8 != (code *)0x0) &&
               (*(longlong *)pcStack_d8 = *(longlong *)pcStack_d8 + -1, *(longlong *)pcStack_d8 == 0
               )) {
              (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
            }
            if (pcStack_c0 != pcVar5) {
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedca28);
              if (plVar14 != (longlong *)0x0) {
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23eedc868);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                uVar11 = DAT_23ed6ce48;
                if (plVar15 != (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e8bc2f0(pcVar26);
                  if (plVar14 == (longlong *)0x0) {
                    auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      FUN_23a334bc0(plVar15);
                      uVar18 = 0xe6;
                      plVar8 = aplStack_78[0];
                      pcVar13 = (code *)auStack_88._0_8_;
                      uVar11 = auStack_88._8_8_;
                    }
                    else {
                      uVar18 = 0xe6;
                      plVar8 = aplStack_78[0];
                      pcVar13 = (code *)auStack_88._0_8_;
                      uVar11 = auStack_88._8_8_;
                    }
                    goto LAB_23e88e26b;
                  }
                  plVar16 = (longlong *)_PyDict_NewPresized(2);
                  PyDict_SetItem(plVar16,uVar11,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  PyDict_SetItem(plVar16,_DAT_23eedcb90,pcStack_c0);
                  *(undefined4 *)(plVar3 + 5) = 0xe5;
                  plVar14 = (longlong *)FUN_23e914090(param_1,plVar15,plVar16);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  if (plVar14 != (longlong *)0x0) {
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    if (plVar8 == (longlong *)0x0) {
                      FUN_23e8ba2b0(auStack_88,_DAT_23eedcb98);
                      if (((code *)auStack_88._0_8_ != pcVar5) &&
                         ((code *)auStack_88._0_8_ != (code *)0x0)) {
                        FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,aplStack_78);
                      }
                      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_88._8_8_);
                    }
                    else {
                      plStack_98 = plVar8;
                      if ((code *)plVar8[1] == PyLong_Type_exref) {
                        lVar12 = plVar8[2];
                        lVar22 = *plVar8;
                        lVar25 = *(longlong *)(DAT_23ed6ccf8 + 0x10);
                        if (lVar12 < 0) {
                          lVar21 = -lVar12;
                          if (lVar12 == -1 || lVar21 < 1) {
                            if (lVar25 < 0) {
                              if (lVar25 != -1 && 0 < -lVar25) goto LAB_23e88e66e;
                            }
                            else if (1 < lVar25) goto LAB_23e88e6f7;
                            iVar7 = -(int)plVar8[3];
                            if (lVar25 < 0) {
LAB_23e88e5a5:
                              iVar20 = -*(int *)(DAT_23ed6ccf8 + 0x18);
                            }
                            else {
LAB_23e88df0d:
                              iVar20 = 0;
                              if (lVar25 != 0) {
                                iVar20 = *(int *)(DAT_23ed6ccf8 + 0x18);
                              }
                            }
                            if (lVar22 == 1) {
                              FUN_23e8be320(&plStack_98);
                              plVar9 = plStack_98;
                              goto LAB_23e88d271;
                            }
                            plVar9 = (longlong *)FUN_23e8bb5f0(iVar20 + iVar7);
                          }
                          else {
                            lVar24 = -lVar25;
                            if (-lVar25 < 0) {
                              lVar24 = lVar25;
                            }
                            if (lVar22 == 1) {
                              bVar27 = lVar25 < 0;
                              lVar25 = lVar24;
                              if (bVar27) {
LAB_23e88ee20:
                                plVar9 = (longlong *)
                                         FUN_23e8be680(plVar8,DAT_23ed6ccf8 + 0x18,lVar24);
                                lVar12 = -plVar9[2];
                                if (-1 < lVar12) {
                                  lVar12 = plVar9[2];
                                }
                                plVar9[2] = lVar12;
                                goto LAB_23e88d271;
                              }
LAB_23e88edf7:
                              plVar9 = (longlong *)FUN_23e8beb80(plVar8,DAT_23ed6ccf8 + 0x18,lVar25)
                              ;
                              goto LAB_23e88d271;
                            }
                            bVar27 = lVar25 < 0;
                            lVar25 = lVar24;
                            if (bVar27) {
LAB_23e88e699:
                              plVar9 = (longlong *)
                                       FUN_23e8be550(plVar8 + 3,lVar21,DAT_23ed6ccf8 + 0x18);
                              plVar9[2] = -plVar9[2];
                            }
                            else {
LAB_23e88e312:
                              plVar9 = (longlong *)
                                       FUN_23e8be900(DAT_23ed6ccf8 + 0x18,lVar25,plVar8 + 3);
                            }
                          }
LAB_23e88df2e:
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            FUN_23a334bc0(plVar8);
                          }
                        }
                        else {
                          if (lVar12 < 2) {
                            if (lVar25 < 0) {
                              if (-lVar25 < 2) {
                                iVar7 = 0;
                                if (lVar12 != 0) {
                                  iVar7 = (int)plVar8[3];
                                }
                                goto LAB_23e88e5a5;
                              }
LAB_23e88e66e:
                              lVar24 = -lVar25;
                              if (lVar22 == 1) {
                                if (lVar12 < 0) goto LAB_23e88ee20;
                                goto LAB_23e88ea67;
                              }
                              lVar21 = -lVar12;
                              if (-lVar12 < 0) {
                                lVar21 = lVar12;
                              }
                              bVar27 = lVar12 < 0;
                              lVar12 = lVar21;
                              if (bVar27) goto LAB_23e88e699;
LAB_23e88e5f9:
                              plVar9 = (longlong *)
                                       FUN_23e8be900(plVar8 + 3,lVar12,DAT_23ed6ccf8 + 0x18);
                              goto LAB_23e88df2e;
                            }
                            if (lVar25 < 2) {
                              iVar7 = 0;
                              if (lVar12 != 0) {
                                iVar7 = (int)plVar8[3];
                              }
                              goto LAB_23e88df0d;
                            }
LAB_23e88e6f7:
                            if (lVar22 != 1) {
                              lVar22 = -lVar12;
                              if (-lVar12 < 0) {
                                lVar22 = lVar12;
                              }
                              bVar27 = lVar12 < 0;
                              lVar12 = lVar22;
                              if (bVar27) goto LAB_23e88e312;
                              goto LAB_23e88e414;
                            }
                            lVar24 = lVar25;
                            if (lVar12 < 0) goto LAB_23e88edf7;
                          }
                          else {
                            lVar24 = -lVar25;
                            if (-lVar25 < 0) {
                              lVar24 = lVar25;
                            }
                            if (lVar22 != 1) {
                              if (-1 < lVar25) {
LAB_23e88e414:
                                plVar9 = (longlong *)
                                         FUN_23e8be550(plVar8 + 3,lVar12,DAT_23ed6ccf8 + 0x18);
                                if (plVar9 != (longlong *)0x0) goto LAB_23e88df2e;
                                goto LAB_23e88e42b;
                              }
                              goto LAB_23e88e5f9;
                            }
                            if (lVar25 < 0) {
LAB_23e88ea67:
                              plVar9 = (longlong *)FUN_23e8beb80(plVar8,DAT_23ed6ccf8 + 0x18,lVar24)
                              ;
                              goto LAB_23e88d271;
                            }
                          }
                          plVar9 = (longlong *)FUN_23e8be680(plVar8,DAT_23ed6ccf8 + 0x18,lVar24);
                        }
                        goto LAB_23e88d271;
                      }
                      cVar6 = FUN_23e8c7160(&plStack_98,DAT_23ed6ccf8);
                      plVar9 = plStack_98;
                      if (cVar6 != '\0') goto LAB_23e88d271;
LAB_23e88e42b:
                      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    uVar18 = 0xe9;
                    plVar9 = plVar8;
                    plVar8 = aplStack_78[0];
                    pcVar13 = (code *)auStack_88._0_8_;
                    uVar11 = auStack_88._8_8_;
                    goto LAB_23e88e26b;
                  }
                }
              }
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar13 = *(code **)(param_1 + 0x60);
              uVar18 = 0xe5;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar11 = *(undefined8 *)(param_1 + 0x68);
              goto LAB_23e88e26b;
            }
LAB_23e88d271:
            lVar12 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar12 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
               (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e88e52d;
            if (*(int *)(lVar12 + 0x68) != 0) {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
            }
            plVar14 = *(longlong **)(param_1 + 0x90);
            if (plVar14 != (longlong *)0x0) goto LAB_23e88e4ab;
          }
          lVar12 = plVar17[1];
          pcStack_d8 = pcStack_c0;
          if (*(code **)(lVar12 + 0xe0) == (code *)0x0) goto LAB_23e88df59;
          pcVar13 = (code *)(**(code **)(lVar12 + 0xe0))();
          pcVar23 = pcVar26;
          if (pcVar13 == (code *)0x0) goto LAB_23e88df7e;
          *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
          if (*(longlong *)pcVar26 == 0) {
            (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
          }
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
          *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
          plVar8 = plVar9;
          if (*(longlong *)pcVar26 == 0) {
            (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
          }
        }
LAB_23e88e378:
        plVar8 = *(longlong **)(param_1 + 0x70);
        pcVar13 = *(code **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0xe0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_c0 = pcStack_d8;
        uVar11 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e88e26b;
      }
      pcStack_d8 = (code *)0x0;
      pcVar23 = pcVar13;
    }
LAB_23e88df7e:
    pcVar26 = pcVar23;
    cVar6 = FUN_23a3591a0(param_1);
    if (cVar6 != '\0') {
      if ((pcVar26 != (code *)0x0) &&
         (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
        FUN_23a334bc0(pcVar26);
      }
      lVar12 = *plVar17;
      *plVar17 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar17);
      }
      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar8 = _DAT_23eedcba0;
      plVar17 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
      *plVar8 = *plVar8 + 1;
      plVar17[3] = (longlong)plVar8;
      if (plVar9 == (longlong *)0x0) {
        FUN_23e8ba2b0(auStack_88,_DAT_23eedcb98);
        if (((code *)auStack_88._0_8_ != pcVar5) && ((code *)auStack_88._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,aplStack_78);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_88._8_8_);
      }
      else {
        lVar12 = FUN_23e94f9d0(param_1,plVar9);
        if (lVar12 != 0) {
          plVar17[4] = lVar12;
          plVar8 = _DAT_23eedcba8;
          *_DAT_23eedcba8 = *_DAT_23eedcba8 + 1;
          plVar17[5] = (longlong)plVar8;
          plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            FUN_23a334bc0();
          }
          if (plVar8 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0xeb;
            plVar17 = (longlong *)FUN_23e914090(param_1,uVar11);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              FUN_23a334bc0();
            }
            if (plVar17 != (longlong *)0x0) {
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                FUN_23a334bc0(plVar17);
              }
              iVar7 = FUN_23e97a530(plVar9);
              if (iVar7 == -1) {
                pcVar13 = *(code **)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar18 = 0xed;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar11 = *(undefined8 *)(param_1 + 0x68);
              }
              else {
                if (iVar7 != 1) {
                  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                  pcVar13 = _Py_TrueStruct_exref;
                  *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
                  lVar12 = *plStack_e0;
                  *plStack_e0 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plStack_e0[1] + 0x30))();
                    goto LAB_23e88c7a8;
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) goto LAB_23e88c7ae;
                  goto LAB_23e88c7bd;
                }
                uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                *(undefined4 *)(plVar3 + 5) = 0xee;
                plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcbb0);
                if (plVar8 != (longlong *)0x0) {
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    FUN_23a334bc0(plVar8);
                  }
                  lVar12 = *(longlong *)_Py_FalseStruct_exref + 1;
                  goto LAB_23e88c711;
                }
                pcVar13 = *(code **)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                uVar18 = 0xee;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar11 = *(undefined8 *)(param_1 + 0x68);
              }
              goto LAB_23e88d3a6;
            }
          }
          pcVar13 = *(code **)(param_1 + 0x60);
          plVar8 = *(longlong **)(param_1 + 0x70);
          uVar18 = 0xeb;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar11 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e88d3a6;
        }
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      *plVar17 = *plVar17 + -1;
      if (*plVar17 == 0) {
        FUN_23a334bc0(plVar17);
        uVar18 = 0xeb;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      else {
        uVar18 = 0xeb;
        plVar8 = aplStack_78[0];
        pcVar13 = (code *)auStack_88._0_8_;
        uVar11 = auStack_88._8_8_;
      }
      goto LAB_23e88d3a6;
    }
    pcVar13 = *(code **)(param_1 + 0x60);
    uVar11 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    aplStack_78[0] = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    auStack_88 = (undefined1  [16])0x0;
    if (pcVar26 != (code *)0x0) {
      pcStack_c0 = pcStack_d8;
      uVar18 = 0xdf;
      goto LAB_23e88e26b;
    }
    uVar18 = 0xdf;
    goto LAB_23e88e296;
  }
  if (plStack_e0 != (longlong *)0x0) goto LAB_23e88c524;
LAB_23e88c85e:
  auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
  auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
  aplStack_78[0] = *(longlong **)(param_1 + 0x70);
  pcVar26 = (code *)0x0;
  plVar9 = (longlong *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar10 = (longlong *)0x0;
  uVar19 = 200;
  uVar18 = 200;
  pcStack_d8 = (code *)0x0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (aplStack_78[0] == (longlong *)0x0) {
    aplStack_78[0] = (longlong *)0x0;
    goto LAB_23e88c8b0;
  }
  goto LAB_23e88d3af;
LAB_23e88e213:
  FUN_23e915740(param_1,auStack_88,_DAT_23eedc940);
  plVar9 = plVar8;
LAB_23e88e24c:
  uVar18 = 0xe3;
  pcStack_c0 = pcStack_d8;
  plVar8 = aplStack_78[0];
  pcVar13 = (code *)auStack_88._0_8_;
  uVar11 = auStack_88._8_8_;
  goto LAB_23e88e26b;
LAB_23e88e894:
  auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
  auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
  aplStack_78[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    FUN_23a334bc0(plVar14);
    goto LAB_23e88e24c;
  }
  uVar18 = 0xe3;
  pcStack_c0 = pcStack_d8;
  plVar8 = aplStack_78[0];
  pcVar13 = (code *)auStack_88._0_8_;
  uVar11 = auStack_88._8_8_;
  goto LAB_23e88e26b;
LAB_23e88e620:
  pcVar13 = *(code **)(param_1 + 0x60);
  plVar8 = *(longlong **)(param_1 + 0x70);
  uVar18 = 0xe3;
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcStack_c0 = pcStack_d8;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar11 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e88e26b;
LAB_23e88e4ab:
  plVar8 = *(longlong **)(param_1 + 0x60);
  plVar15 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar16 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar14;
  *plVar14 = *plVar14 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
LAB_23e88e52d:
  pcVar13 = *(code **)(param_1 + 0x60);
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar18 = 0xdf;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar11 = *(undefined8 *)(param_1 + 0x68);
LAB_23e88e26b:
  aplStack_78[0] = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
  if (*(longlong *)pcVar26 == 0) {
    FUN_23a334bc0(pcVar26);
  }
  pcStack_d8 = pcStack_c0;
LAB_23e88e296:
  lVar12 = *plVar17;
  *plVar17 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
LAB_23e88d3a6:
  auStack_88._8_8_ = uVar11;
  auStack_88._0_8_ = pcVar13;
  aplStack_78[0] = plVar8;
  uVar19 = uVar18;
  if (aplStack_78[0] == (longlong *)0x0) {
LAB_23e88c8b0:
    plVar8 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar17 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar17;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar13 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar13 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar18;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar22 = plVar8[-1];
    puVar2 = *(undefined8 **)(lVar12 + 8);
    *puVar2 = plVar8 + -2;
    plVar8[-2] = lVar12;
    plVar8[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar12 + 8) = plVar8 + -2;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
    }
  }
  else {
LAB_23e88d3af:
    plVar8 = aplStack_78[0];
    plVar17 = DAT_23ed6a4f8;
    if ((longlong *)aplStack_78[0][3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar13 = _PyRuntime_exref;
      plVar17[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar12 = *(longlong *)(pcVar13 + 0x1f8);
      *(undefined4 *)((longlong)plVar17 + 0x24) = uVar19;
      *(undefined4 *)(plVar17 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar22 = plVar17[-1];
      puVar2 = *(undefined8 **)(lVar12 + 8);
      *puVar2 = plVar17 + -2;
      plVar17[-2] = lVar12;
      plVar17[-1] = (ulonglong)((uint)lVar22 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar12 + 8) = plVar17 + -2;
      plVar17[2] = (longlong)plVar8;
      *plVar8 = *plVar8 + 1;
      plVar8 = plVar17;
      if ((aplStack_78[0] != (longlong *)0x0) &&
         (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
        (**(code **)(aplStack_78[0][1] + 0x30))();
      }
    }
  }
  aplStack_78[0] = plVar8;
  FUN_23e8bba40(plVar3,"oooooo",plVar1,plStack_e0,plVar10,plVar9,pcVar26,pcStack_d8);
  if (_DAT_23eede650 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede650 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar12 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar3 = aplStack_78[0];
  uVar4 = auStack_88._8_8_;
  uVar11 = auStack_88._0_8_;
  plVar8[0xf] = 0;
  auStack_88 = (undefined1  [16])0x0;
  aplStack_78[0] = (longlong *)0x0;
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar12 = *plStack_e0, *plStack_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar26 != (code *)0x0) &&
     (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
    (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
  }
  if ((pcStack_d8 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_d8, *(longlong *)pcStack_d8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
  }
  *plVar1 = *plVar1 + -1;
  aplStack_78[0] = plVar3;
  auStack_88._0_8_ = uVar11;
  auStack_88._8_8_ = uVar4;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_88._0_8_,auStack_88._8_8_,aplStack_78[0]);
  return (code *)0x0;
}
