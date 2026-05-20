/* ===== 23e893cf0 workers.fishing.store_fish:314 ===== */
/* ghidra_name=FUN_23e893cf0 entry=23e893cf0 size=10438 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e893cf0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  code *pcVar9;
  code *pcVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined8 uVar14;
  longlong *plVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  longlong *plVar19;
  code *pcVar20;
  undefined4 uVar21;
  code *pcStack_e0;
  code *pcStack_d0;
  code *pcStack_c8;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  code *pcStack_78;
  code *pcStack_70;
  undefined8 uStack_68;
  
  plVar11 = _DAT_23eede618;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plStack_88 = (longlong *)0x0;
  auStack_98._0_8_ = 0;
  auStack_98._8_8_ = 0;
  if (_DAT_23eede618 == (longlong *)0x0) {
LAB_23e893d56:
    _DAT_23eede618 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede610,DAT_23eede708,0x50);
  }
  else {
    lVar12 = *_DAT_23eede618;
    if (1 < lVar12) {
      *_DAT_23eede618 = lVar12 + -1;
      goto LAB_23e893d56;
    }
    if (_DAT_23eede618[2] != 0) {
      *_DAT_23eede618 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e893d56;
    }
  }
  plVar5 = _DAT_23eede618;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eede618 + 9;
  lVar3 = *(longlong *)(lVar12 + 8);
  _DAT_23eede618[0xf] = lVar3;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  pcVar9 = (code *)FUN_23a38cc10(param_1,plVar2,DAT_23ed6ce48);
  if (pcVar9 == (code *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar17 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar16 = (code *)0x0;
    pcVar10 = (code *)0x0;
    uVar21 = 0x13f;
    pcStack_d0 = (code *)0x0;
    pcStack_c8 = (code *)0x0;
    pcStack_e0 = (code *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e894f71;
  }
  pcVar10 = (code *)FUN_23a38cc10(param_1,plVar2,DAT_23eedca70);
  if (pcVar10 == (code *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar17 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar16 = (code *)0x0;
    uVar21 = 0x140;
    pcStack_d0 = (code *)0x0;
    pcStack_c8 = (code *)0x0;
    pcStack_e0 = (code *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e894f71;
  }
  pcStack_e0 = (code *)FUN_23a38cc10(param_1,plVar2,DAT_23eedcb00);
  if (pcStack_e0 == (code *)0x0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar17 = (code *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar16 = (code *)0x0;
    uVar21 = 0x141;
    pcStack_d0 = (code *)0x0;
    pcStack_c8 = (code *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e894f71;
  }
  plVar11 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
  plVar13 = _DAT_23eedcc50;
  lVar12 = *(longlong *)(param_1 + 0x10);
  plVar15 = *(longlong **)(lVar12 + 0xe20);
  if (plVar15 == (longlong *)0x0) {
    plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
  }
  else {
    lVar3 = plVar15[3];
    *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
    *(longlong *)(lVar12 + 0xe20) = lVar3;
    *plVar15 = 1;
  }
  pcVar16 = _PyRuntime_exref;
  plVar15[4] = 0;
  lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
  lVar3 = plVar15[-1];
  puVar4 = *(undefined8 **)(lVar12 + 8);
  *puVar4 = plVar15 + -2;
  plVar15[-2] = lVar12;
  plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
  *(longlong **)(lVar12 + 8) = plVar15 + -2;
  *plVar13 = *plVar13 + 1;
  plVar15[3] = (longlong)plVar13;
  pcVar16 = DAT_23ed6cd28;
  if (DAT_23ed6a4c0 == (longlong *)0x0) {
    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
      goto LAB_23e893efe;
    }
    goto LAB_23e8957d0;
  }
LAB_23e893efe:
  pcStack_70 = pcVar16;
  pcStack_78 = pcVar9;
  lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
  if (lVar12 == 0) {
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
  }
  else {
    plVar15[4] = lVar12;
    plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (plVar13 != (longlong *)0x0) {
      *(undefined4 *)(plVar5 + 5) = 0x143;
      plVar11 = (longlong *)FUN_23e914090(param_1,plVar11,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar11 == (longlong *)0x0) {
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        pcVar17 = (code *)0x0;
        pcVar16 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar21 = 0x143;
        pcStack_d0 = (code *)0x0;
        pcStack_c8 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
        goto LAB_23e894f71;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      plVar11 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
      plVar13 = _DAT_23eedcc58;
      lVar12 = *(longlong *)(param_1 + 0x10);
      plVar15 = *(longlong **)(lVar12 + 0xe38);
      if (plVar15 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,5);
      }
      else {
        lVar3 = plVar15[3];
        *(int *)(lVar12 + 0xec8) = *(int *)(lVar12 + 0xec8) + -1;
        *(longlong *)(lVar12 + 0xe38) = lVar3;
        *plVar15 = 1;
      }
      pcVar16 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
      lVar12 = *(longlong *)(pcVar16 + 0x1f8);
      *(undefined1 (*) [16])(plVar15 + 6) = (undefined1  [16])0x0;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar3 = plVar15[-1];
      puVar4 = *(undefined8 **)(lVar12 + 8);
      *puVar4 = plVar15 + -2;
      plVar15[-2] = lVar12;
      plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar12 + 8) = plVar15 + -2;
      *plVar13 = *plVar13 + 1;
      plVar15[3] = (longlong)plVar13;
      pcVar16 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar13 == (longlong *)0x0) goto LAB_23e8957d0;
        *plVar13 = *plVar13 + 1;
        DAT_23ed6a4c0 = plVar13;
      }
      pcStack_70 = pcVar16;
      pcStack_78 = pcVar10;
      lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
      if (lVar12 == 0) {
LAB_23e895420:
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        uVar21 = 0x144;
      }
      else {
        plVar15[4] = lVar12;
        plVar13 = _DAT_23eedcc28;
        *_DAT_23eedcc28 = *_DAT_23eedcc28 + 1;
        plVar15[5] = (longlong)plVar13;
        pcVar16 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar13 == (longlong *)0x0) goto LAB_23e8957d0;
          *plVar13 = *plVar13 + 1;
          DAT_23ed6a4c0 = plVar13;
        }
        pcStack_70 = pcVar16;
        pcStack_78 = pcStack_e0;
        lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
        if (lVar12 == 0) goto LAB_23e895420;
        plVar15[6] = lVar12;
        plVar13 = _DAT_23eedcc60;
        *_DAT_23eedcc60 = *_DAT_23eedcc60 + 1;
        plVar15[7] = (longlong)plVar13;
        plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (plVar13 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x144;
          pcStack_d0 = (code *)0x0;
          pcStack_c8 = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar16 = (code *)0x0;
          goto LAB_23e894f71;
        }
        *(undefined4 *)(plVar5 + 5) = 0x144;
        plVar11 = (longlong *)FUN_23e914090(param_1,plVar11,plVar13);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if (plVar11 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x144;
          pcStack_d0 = (code *)0x0;
          pcStack_c8 = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = (longlong *)0x0;
          goto LAB_23e894f71;
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar5 + 5) = 0x147;
        plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eedcc68);
        if (plVar11 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x147;
          pcStack_d0 = (code *)0x0;
          pcStack_c8 = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar16 = (code *)0x0;
          goto LAB_23e894f71;
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedca10);
        uVar14 = _DAT_23eedc9d8;
        if (plVar11 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x148;
          pcStack_d0 = (code *)0x0;
          pcStack_c8 = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar16 = (code *)0x0;
          goto LAB_23e894f71;
        }
        *(undefined4 *)(plVar5 + 5) = 0x148;
        uStack_68 = uVar14;
        pcStack_78 = pcVar10;
        pcStack_70 = pcStack_e0;
        plVar15 = (longlong *)FUN_23e9578c0(param_1,plVar11,_DAT_23eedcc70,&pcStack_78);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)0x0;
        if (plVar15 == (longlong *)0x0) {
LAB_23e8957e8:
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          plStack_88 = *(longlong **)(param_1 + 0x70);
          pcVar17 = (code *)0x0;
          pcVar16 = (code *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar21 = 0x148;
          pcStack_d0 = (code *)0x0;
          pcStack_c8 = (code *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e894f71;
        }
        iVar8 = FUN_23a35f020(plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (iVar8 != -1) {
          if (iVar8 == 0) {
            uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
            *(undefined4 *)(plVar5 + 5) = 0x149;
            plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eedcc78);
            if (plVar11 == (longlong *)0x0) {
              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plStack_88 = *(longlong **)(param_1 + 0x70);
              pcVar17 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar21 = 0x149;
              pcStack_d0 = (code *)0x0;
              pcStack_c8 = (code *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar16 = (code *)0x0;
              goto LAB_23e894f71;
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            pcVar18 = _Py_FalseStruct_exref;
            pcVar17 = (code *)0x0;
            plVar11 = (longlong *)0x0;
            pcVar20 = (code *)0x0;
            pcStack_d0 = (code *)0x0;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
            pcStack_c8 = (code *)0x0;
LAB_23e894ca0:
            lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar5 = *(longlong **)(lVar12 + 0x28);
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
            plVar15 = (longlong *)plVar5[2];
            *(undefined4 *)(plVar5 + 8) = 0xffffffff;
            if (plVar15 != (longlong *)0x0) {
              plVar5[2] = 0;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
            }
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))(plVar5);
            }
            plVar5[0xf] = 0;
            pcVar16 = pcVar20;
LAB_23e894d11:
            *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
            if (*(longlong *)pcVar9 == 0) {
              (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
            }
            *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
            if (*(longlong *)pcVar10 == 0) {
              (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
            }
            lVar12 = *(longlong *)pcStack_e0;
            *(longlong *)pcStack_e0 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(*(longlong *)(pcStack_e0 + 8) + 0x30))(pcStack_e0);
            }
            if ((pcVar16 != (code *)0x0) &&
               (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
              (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if ((pcStack_c8 != (code *)0x0) &&
               (lVar12 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar12 + -1,
               lVar12 + -1 == 0)) {
              (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))(pcStack_c8);
            }
            if ((pcVar17 != (code *)0x0) &&
               (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
              (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
            }
            if ((pcStack_d0 != (code *)0x0) &&
               (lVar12 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar12 + -1,
               lVar12 + -1 == 0)) {
              (**(code **)(*(longlong *)(pcStack_d0 + 8) + 0x30))(pcStack_d0);
            }
            lVar12 = *plVar1;
            *plVar1 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 != 0) {
              return pcVar18;
            }
            (**(code **)(plVar2[1] + 0x30))(plVar2);
            return pcVar18;
          }
          lVar12 = FUN_23e8dbb80();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,auStack_98,_DAT_23eedc9c0);
          }
          else {
            plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedc9c8);
            if (plVar11 != (longlong *)0x0) {
              lVar12 = *(longlong *)(DAT_23eedc7f0 + 0x20);
              if (*(char *)(lVar12 + 10) == '\0') {
                plVar15 = (longlong *)FUN_23a37a020(DAT_23eedc7f0,_DAT_23eedcc80);
                if (plVar15 == (longlong *)0x0) goto LAB_23e895890;
                lVar12 = *plVar15;
LAB_23e895879:
                if (lVar12 == 0) goto LAB_23e895890;
              }
              else {
                iVar8 = *(int *)(lVar12 + 0xc);
                if (*(int *)(lVar12 + 0xc) == 0) {
                  *(int *)(lVar12 + 0xc) = DAT_23ec1555c;
                  iVar8 = DAT_23ec1555c;
                  DAT_23ec1555c = DAT_23ec1555c + 1;
                }
                if (_DAT_23ec15538 != iVar8) {
                  _DAT_23ec15538 = iVar8;
                  _DAT_23eede600 =
                       FUN_23e8cbd60(lVar12,_DAT_23eedcc80,*(undefined8 *)(_DAT_23eedcc80 + 0x18));
                }
                if (-1 < _DAT_23eede600) {
                  lVar3 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                  if (*(longlong *)(lVar3 + 8 + _DAT_23eede600 * 0x10) != 0) goto LAB_23e8942f7;
                  _DAT_23eede600 =
                       FUN_23e8cbd60(lVar12,_DAT_23eedcc80,*(undefined8 *)(_DAT_23eedcc80 + 0x18));
                  if (-1 < _DAT_23eede600) {
                    lVar12 = *(longlong *)(lVar3 + 8 + _DAT_23eede600 * 0x10);
                    goto LAB_23e895879;
                  }
                }
LAB_23e895890:
                plVar15 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedcc80);
                if ((plVar15 == (longlong *)0x0) || (*plVar15 == 0)) {
                  FUN_23e915740(param_1,auStack_98,_DAT_23eedcc80);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  uVar21 = 0x14d;
                  goto LAB_23e895467;
                }
              }
LAB_23e8942f7:
              *(undefined4 *)(plVar5 + 5) = 0x14d;
              plVar15 = (longlong *)FUN_23e914090(param_1,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar15 == (longlong *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                pcVar17 = (code *)0x0;
                pcVar16 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0x14d;
                pcStack_d0 = (code *)0x0;
                pcStack_c8 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
                goto LAB_23e894f71;
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedca10);
              if (plVar11 == (longlong *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                pcVar17 = (code *)0x0;
                pcVar16 = (code *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0x150;
                pcStack_d0 = (code *)0x0;
                pcStack_c8 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
                goto LAB_23e894f71;
              }
              *(undefined4 *)(plVar5 + 5) = 0x150;
              pcVar16 = (code *)FUN_23e91bfe0(param_1,plVar11,DAT_23eedca10);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              pcVar20 = _Py_NoneStruct_exref;
              if (pcVar16 == (code *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                pcVar17 = (code *)0x0;
                plVar11 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0x150;
                pcStack_d0 = (code *)0x0;
                pcStack_c8 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e894f71;
              }
              if (pcVar16 == _Py_NoneStruct_exref) {
                uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                *(undefined4 *)(plVar5 + 5) = 0x152;
                plVar11 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eedcc88);
                if (plVar11 == (longlong *)0x0) {
                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plStack_88 = *(longlong **)(param_1 + 0x70);
                  pcStack_d0 = (code *)0x0;
                  pcVar17 = (code *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar21 = 0x152;
                  pcStack_c8 = (code *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar11 = (longlong *)0x0;
                  goto LAB_23e894f71;
                }
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                pcVar18 = _Py_FalseStruct_exref;
                pcVar17 = (code *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_d0 = (code *)0x0;
                *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
                pcStack_c8 = (code *)0x0;
                goto LAB_23e894ca0;
              }
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedcbf8);
              if (plVar11 == (longlong *)0x0) goto LAB_23e895af9;
              pcVar17 = (code *)FUN_23e8bc2f0(plVar1,_DAT_23eedca30);
              if (pcVar17 == (code *)0x0) {
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar11 = *plVar11 + -1;
                uVar21 = 0x157;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                  pcStack_d0._0_4_ = 0x157;
                  uVar21 = pcStack_d0._0_4_;
                }
              }
              else {
                *(undefined4 *)(plVar5 + 5) = 0x156;
                pcStack_78 = pcVar16;
                pcStack_70 = pcVar17;
                plVar15 = (longlong *)FUN_23e94ed00(param_1,plVar11,&pcStack_78);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                if (*(longlong *)pcVar17 == 0) {
                  (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
                }
                if (plVar15 != (longlong *)0x0) {
                  plVar13 = (longlong *)FUN_23a388310(plVar15);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    plVar11 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                    if ((plVar11 == (longlong *)0x0) &&
                       (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4),
                       plVar11 == (longlong *)0x0)) {
                      pcVar17 = (code *)0x0;
                      pcStack_d0 = (code *)0x0;
                      pcStack_c8 = (code *)0x0;
                    }
                    else {
                      pcStack_c8 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if ((pcStack_c8 == (code *)0x0) &&
                         (pcStack_c8 = (code *)FUN_23a3c1b70(param_1,auStack_98,1,4),
                         pcStack_c8 == (code *)0x0)) {
                        pcVar17 = (code *)0x0;
                        pcStack_d0 = (code *)0x0;
                      }
                      else {
                        pcVar17 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                        if ((pcVar17 == (code *)0x0) &&
                           (pcVar17 = (code *)FUN_23a3c1b70(param_1,auStack_98,2,4),
                           pcVar17 == (code *)0x0)) {
                          pcStack_d0 = (code *)0x0;
                        }
                        else {
                          pcStack_d0 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                          if (((pcStack_d0 != (code *)0x0) ||
                              (pcStack_d0 = (code *)FUN_23a3c1b70(param_1,auStack_98,3,4),
                              pcStack_d0 != (code *)0x0)) &&
                             (cVar7 = FUN_23a3884a0(param_1,auStack_98,plVar13,4), cVar7 != '\0')) {
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))(plVar13);
                            }
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            if (*(longlong *)pcStack_c8 == 0) {
                              (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))();
                            }
                            if (*(longlong *)pcVar17 == 0) {
                              (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
                            }
                            if (*(longlong *)pcStack_d0 == 0) {
                              (**(code **)(*(longlong *)(pcStack_d0 + 8) + 0x30))();
                            }
                            iVar8 = FUN_23a35f020(plVar11);
                            if (iVar8 == -1) {
                              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              uVar21 = 0x15a;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e894f71;
                            }
                            if (iVar8 == 0) {
                              uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar13 = _DAT_23eedccc8;
                              lVar12 = *(longlong *)(param_1 + 0x10);
                              plVar15 = *(longlong **)(lVar12 + 0xe28);
                              if (plVar15 == (longlong *)0x0) {
                                plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                              }
                              else {
                                lVar3 = plVar15[3];
                                *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                                *(longlong *)(lVar12 + 0xe28) = lVar3;
                                *plVar15 = 1;
                              }
                              pcVar20 = _PyRuntime_exref;
                              *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
                              pcVar18 = _DAT_23eedcc38;
                              lVar12 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar3 = plVar15[-1];
                              puVar4 = *(undefined8 **)(lVar12 + 8);
                              *puVar4 = plVar15 + -2;
                              plVar15[-2] = lVar12;
                              plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
                              *(longlong **)(lVar12 + 8) = plVar15 + -2;
                              plVar19 = DAT_23ed6a4c0;
                              *plVar13 = *plVar13 + 1;
                              plVar15[3] = (longlong)plVar13;
                              if (plVar19 == (longlong *)0x0) {
                                plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar19 == (longlong *)0x0) goto LAB_23e8957d0;
                                *plVar19 = *plVar19 + 1;
                                DAT_23ed6a4c0 = plVar19;
                              }
                              pcStack_78 = pcStack_d0;
                              pcStack_70 = pcVar18;
                              lVar12 = FUN_23e94ed00(param_1,plVar19,&pcStack_78);
                              if (lVar12 != 0) {
                                plVar15[4] = lVar12;
                                plVar13 = _DAT_23eedcc60;
                                *_DAT_23eedcc60 = *_DAT_23eedcc60 + 1;
                                plVar15[5] = (longlong)plVar13;
                                plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                }
                                if (plVar13 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar5 + 5) = 0x166;
                                  plVar15 = (longlong *)FUN_23e914090(param_1,uVar14);
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  if (plVar15 != (longlong *)0x0) {
                                    *plVar15 = *plVar15 + -1;
                                    lVar12 = *plVar15;
joined_r0x00023e895fe0:
                                    if (lVar12 == 0) {
                                      FUN_23a334bc0(plVar15);
                                    }
                                    FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                    pcVar18 = _Py_FalseStruct_exref;
                                    *(longlong *)_Py_FalseStruct_exref =
                                         *(longlong *)_Py_FalseStruct_exref + 1;
                                    goto LAB_23e894d11;
                                  }
                                }
                                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar21 = 0x166;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e894f71;
                              }
                              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              uVar21 = 0x166;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar15 = *plVar15 + -1;
                              lVar12 = *plVar15;
                            }
                            else {
                              uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar13 = _DAT_23eedcc90;
                              lVar12 = *(longlong *)(param_1 + 0x10);
                              plVar15 = *(longlong **)(lVar12 + 0xe28);
                              if (plVar15 == (longlong *)0x0) {
                                plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                              }
                              else {
                                lVar3 = plVar15[3];
                                *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                                *(longlong *)(lVar12 + 0xe28) = lVar3;
                                *plVar15 = 1;
                              }
                              pcVar20 = _PyRuntime_exref;
                              *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
                              pcVar18 = _DAT_23eedcc38;
                              lVar12 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar3 = plVar15[-1];
                              puVar4 = *(undefined8 **)(lVar12 + 8);
                              *puVar4 = plVar15 + -2;
                              plVar15[-2] = lVar12;
                              plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
                              *(longlong **)(lVar12 + 8) = plVar15 + -2;
                              plVar19 = DAT_23ed6a4c0;
                              *plVar13 = *plVar13 + 1;
                              plVar15[3] = (longlong)plVar13;
                              if (plVar19 == (longlong *)0x0) {
                                plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar19 == (longlong *)0x0) {
LAB_23e8957d0:
                                  PyErr_PrintEx(0);
                                  Py_Exit(1);
                                  goto LAB_23e8957e8;
                                }
                                *plVar19 = *plVar19 + 1;
                                DAT_23ed6a4c0 = plVar19;
                              }
                              pcStack_78 = pcStack_d0;
                              pcStack_70 = pcVar18;
                              lVar12 = FUN_23e94ed00(param_1,plVar19,&pcStack_78);
                              if (lVar12 != 0) {
                                plVar15[4] = lVar12;
                                plVar13 = _DAT_23eedcc60;
                                *_DAT_23eedcc60 = *_DAT_23eedcc60 + 1;
                                plVar15[5] = (longlong)plVar13;
                                plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                }
                                if (plVar13 != (longlong *)0x0) {
                                  *(undefined4 *)(plVar5 + 5) = 0x15b;
                                  plVar15 = (longlong *)FUN_23e914090(param_1,uVar14);
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  if (plVar15 != (longlong *)0x0) {
                                    *plVar15 = *plVar15 + -1;
                                    if (*plVar15 == 0) {
                                      FUN_23a334bc0(plVar15);
                                    }
                                    uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    plVar13 = _DAT_23eedcc58;
                                    plVar15 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5);
                                    *plVar13 = *plVar13 + 1;
                                    plVar15[3] = (longlong)plVar13;
                                    lVar12 = FUN_23e94f9d0(param_1,pcStack_c8,DAT_23ed6cd28);
                                    if (lVar12 != 0) {
                                      plVar15[4] = lVar12;
                                      plVar13 = _DAT_23eedcc28;
                                      *_DAT_23eedcc28 = *_DAT_23eedcc28 + 1;
                                      plVar15[5] = (longlong)plVar13;
                                      lVar12 = FUN_23e94f9d0(param_1,pcVar17,DAT_23ed6cd28);
                                      if (lVar12 != 0) {
                                        plVar15[6] = lVar12;
                                        plVar13 = _DAT_23eedcc60;
                                        *_DAT_23eedcc60 = *_DAT_23eedcc60 + 1;
                                        plVar15[7] = (longlong)plVar13;
                                        plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                                        *plVar15 = *plVar15 + -1;
                                        if (*plVar15 == 0) {
                                          FUN_23a334bc0(plVar15);
                                        }
                                        if (plVar13 != (longlong *)0x0) {
                                          *(undefined4 *)(plVar5 + 5) = 0x15c;
                                          plVar15 = (longlong *)FUN_23e914090(param_1,uVar14);
                                          *plVar13 = *plVar13 + -1;
                                          if (*plVar13 == 0) {
                                            FUN_23a334bc0(plVar13);
                                          }
                                          if (plVar15 != (longlong *)0x0) {
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                                            *(undefined4 *)(plVar5 + 5) = 0x15d;
                                            plVar15 = (longlong *)FUN_23e94bb80(param_1,uVar14);
                                            if (plVar15 == (longlong *)0x0) {
                                              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                              plStack_88 = *(longlong **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar21 = 0x15d;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e894f71;
                                            }
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            plVar15 = (longlong *)
                                                      FUN_23e8bc2f0(plVar1,DAT_23eedca10);
                                            uVar14 = _DAT_23eedcca0;
                                            if (plVar15 != (longlong *)0x0) {
                                              *(undefined4 *)(plVar5 + 5) = 0x15f;
                                              pcStack_78 = pcStack_c8;
                                              uStack_68 = uVar14;
                                              pcStack_70 = pcVar17;
                                              plVar13 = (longlong *)
                                                        FUN_23e9578c0(param_1,plVar15,_DAT_23eedcc70
                                                                      ,&pcStack_78);
                                              *plVar15 = *plVar15 + -1;
                                              if (*plVar15 == 0) {
                                                FUN_23a334bc0(plVar15);
                                              }
                                              if (plVar13 != (longlong *)0x0) {
                                                iVar8 = FUN_23a35f020();
                                                lVar12 = *plVar13 + -1;
                                                if (iVar8 == -1) {
                                                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
                                                  plStack_88 = *(longlong **)(param_1 + 0x70);
                                                  uVar21 = 0x15f;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar13 = lVar12;
                                                  if (lVar12 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                    uVar21 = 0x15f;
                                                  }
                                                  goto LAB_23e894f71;
                                                }
                                                *plVar13 = lVar12;
                                                if (lVar12 == 0) {
                                                  FUN_23a334bc0(plVar13);
                                                }
                                                if (iVar8 == 0) {
                                                  uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  *(undefined4 *)(plVar5 + 5) = 0x164;
                                                  plVar15 = (longlong *)
                                                            FUN_23e94bb80(param_1,uVar14);
                                                  if (plVar15 == (longlong *)0x0) {
                                                    auStack_98._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_98._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    uVar21 = 0x164;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e894f71;
                                                  }
                                                  *plVar15 = *plVar15 + -1;
                                                  lVar12 = *plVar15;
                                                  goto joined_r0x00023e895fe0;
                                                }
                                                lVar12 = FUN_23e8dbb80();
                                                if (lVar12 == 0) {
                                                  FUN_23e915740(param_1,auStack_98,_DAT_23eedc9c0);
                                                  uVar21 = 0x160;
                                                  goto LAB_23e894f71;
                                                }
                                                plVar15 = (longlong *)
                                                          FUN_23e8bc2f0(lVar12,_DAT_23eedc9c8);
                                                if (plVar15 != (longlong *)0x0) {
                                                  lVar12 = *(longlong *)(DAT_23eedc7f0 + 0x20);
                                                  if (*(char *)(lVar12 + 10) == '\0') {
                                                    plVar13 = (longlong *)
                                                              FUN_23a37a020(DAT_23eedc7f0,
                                                                            _DAT_23eedcca8);
                                                    if (plVar13 == (longlong *)0x0)
                                                    goto LAB_23e896568;
                                                    lVar12 = *plVar13;
LAB_23e89655f:
                                                    if (lVar12 == 0) goto LAB_23e896568;
                                                  }
                                                  else {
                                                    iVar8 = *(int *)(lVar12 + 0xc);
                                                    if (*(int *)(lVar12 + 0xc) == 0) {
                                                      *(int *)(lVar12 + 0xc) = DAT_23ec1555c;
                                                      iVar8 = DAT_23ec1555c;
                                                      DAT_23ec1555c = DAT_23ec1555c + 1;
                                                    }
                                                    if (_DAT_23ec1553c != iVar8) {
                                                      _DAT_23ec1553c = iVar8;
                                                      _DAT_23eede608 =
                                                           FUN_23e8cbd60(lVar12,_DAT_23eedcca8,
                                                                         *(undefined8 *)
                                                                          (_DAT_23eedcca8 + 0x18));
                                                    }
                                                    if (-1 < _DAT_23eede608) {
                                                      lVar3 = lVar12 + 0x20 +
                                                              (1L << (*(byte *)(lVar12 + 9) & 0x3f))
                                                      ;
                                                      if (*(longlong *)
                                                           (lVar3 + 8 + _DAT_23eede608 * 0x10) != 0)
                                                      goto LAB_23e894af1;
                                                      _DAT_23eede608 =
                                                           FUN_23e8cbd60(lVar12,_DAT_23eedcca8,
                                                                         *(undefined8 *)
                                                                          (_DAT_23eedcca8 + 0x18));
                                                      if (-1 < _DAT_23eede608) {
                                                        lVar12 = *(longlong *)
                                                                  (lVar3 + 8 + _DAT_23eede608 * 0x10
                                                                  );
                                                        goto LAB_23e89655f;
                                                      }
                                                    }
LAB_23e896568:
                                                    plVar13 = (longlong *)
                                                              FUN_23a37a020(DAT_23ed6ccc0,
                                                                            _DAT_23eedcca8);
                                                    if ((plVar13 == (longlong *)0x0) ||
                                                       (*plVar13 == 0)) {
                                                      FUN_23e915740(param_1,auStack_98,
                                                                    _DAT_23eedcca8);
                                                      lVar12 = *plVar15;
                                                      *plVar15 = lVar12 + -1;
                                                      if (lVar12 + -1 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      uVar21 = 0x160;
                                                      goto LAB_23e894f71;
                                                    }
                                                  }
LAB_23e894af1:
                                                  *(undefined4 *)(plVar5 + 5) = 0x160;
                                                  plVar13 = (longlong *)
                                                            FUN_23e914090(param_1,plVar15);
                                                  lVar12 = *plVar15;
                                                  *plVar15 = lVar12 + -1;
                                                  if (lVar12 + -1 == 0) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  if (plVar13 != (longlong *)0x0) {
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                    plVar13 = _DAT_23eedccb0;
                                                    plVar15 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),3);
                                                    *plVar13 = *plVar13 + 1;
                                                    plVar15[3] = (longlong)plVar13;
                                                    lVar12 = FUN_23e94f9d0(param_1,pcVar9,
                                                                           DAT_23ed6cd28);
                                                    if (lVar12 != 0) {
                                                      plVar15[4] = lVar12;
                                                      plVar13 = _DAT_23eedccb8;
                                                      *_DAT_23eedccb8 = *_DAT_23eedccb8 + 1;
                                                      plVar15[5] = (longlong)plVar13;
                                                      plVar13 = (longlong *)
                                                                PyUnicode_Join(DAT_23ed6cd28,plVar15
                                                                              );
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      if (plVar13 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar5 + 5) = 0x161;
                                                        plVar15 = (longlong *)
                                                                  FUN_23e914090(param_1,uVar14);
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          pcVar18 = _Py_TrueStruct_exref;
                                                          *(longlong *)_Py_TrueStruct_exref =
                                                               *(longlong *)_Py_TrueStruct_exref + 1
                                                          ;
                                                          pcVar20 = pcVar16;
                                                          goto LAB_23e894ca0;
                                                        }
                                                      }
                                                      auStack_98._0_8_ =
                                                           *(undefined8 *)(param_1 + 0x60);
                                                      auStack_98._8_8_ =
                                                           *(undefined8 *)(param_1 + 0x68);
                                                      plStack_88 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar21 = 0x161;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e894f71;
                                                    }
                                                    auStack_98._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_98._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                                    uVar21 = 0x161;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar15 = *plVar15 + -1;
                                                    lVar12 = *plVar15;
                                                    goto joined_r0x00023e8961e7;
                                                  }
                                                }
                                                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                                uVar21 = 0x160;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                goto LAB_23e894f71;
                                              }
                                            }
                                            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            plStack_88 = *(longlong **)(param_1 + 0x70);
                                            uVar21 = 0x15f;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e894f71;
                                          }
                                        }
                                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        plStack_88 = *(longlong **)(param_1 + 0x70);
                                        uVar21 = 0x15c;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e894f71;
                                      }
                                    }
                                    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                    plStack_88 = *(longlong **)(param_1 + 0x70);
                                    uVar21 = 0x15c;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *plVar15 = *plVar15 + -1;
                                    lVar12 = *plVar15;
                                    goto joined_r0x00023e8961e7;
                                  }
                                }
                                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                plStack_88 = *(longlong **)(param_1 + 0x70);
                                uVar21 = 0x15b;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e894f71;
                              }
                              auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plStack_88 = *(longlong **)(param_1 + 0x70);
                              uVar21 = 0x15b;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *plVar15 = *plVar15 + -1;
                              lVar12 = *plVar15;
                            }
joined_r0x00023e8961e7:
                            if (lVar12 == 0) {
                              FUN_23a334bc0(plVar15);
                            }
                            goto LAB_23e894f71;
                          }
                        }
                      }
                    }
                    plVar15 = plStack_88;
                    uVar6 = auStack_98._8_8_;
                    uVar14 = auStack_98._0_8_;
                    plStack_88 = (longlong *)0x0;
                    auStack_98 = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    plStack_88 = (longlong *)0x0;
                    auStack_98._0_8_ = 0;
                    auStack_98._8_8_ = 0;
                    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if ((pcStack_c8 != (code *)0x0) &&
                       (lVar12 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar12 + -1,
                       lVar12 + -1 == 0)) {
                      (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))();
                    }
                    if ((pcVar17 != (code *)0x0) &&
                       (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)
                       ) {
                      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
                    }
                    if ((pcStack_d0 != (code *)0x0) &&
                       (lVar12 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar12 + -1,
                       lVar12 + -1 == 0)) {
                      (**(code **)(*(longlong *)(pcStack_d0 + 8) + 0x30))();
                    }
                    plStack_88 = plVar15;
                    auStack_98._0_8_ = uVar14;
                    auStack_98._8_8_ = uVar6;
                    uVar21 = 0x156;
                    goto LAB_23e895b18;
                  }
                }
LAB_23e895af9:
                plStack_88 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar21 = 0x156;
              }
LAB_23e895b18:
              pcVar17 = (code *)0x0;
              plVar11 = (longlong *)0x0;
              pcStack_d0 = (code *)0x0;
              pcStack_c8 = (code *)0x0;
              goto LAB_23e894f71;
            }
            plStack_88 = *(longlong **)(param_1 + 0x70);
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          pcVar16 = (code *)0x0;
          pcStack_d0 = (code *)0x0;
          pcVar17 = (code *)0x0;
          plVar11 = (longlong *)0x0;
          uVar21 = 0x14d;
          pcStack_c8 = (code *)0x0;
          goto LAB_23e894f71;
        }
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plStack_88 = *(longlong **)(param_1 + 0x70);
        uVar21 = 0x148;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
LAB_23e895467:
      pcStack_d0 = (code *)0x0;
      pcVar17 = (code *)0x0;
      plVar11 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      pcStack_c8 = (code *)0x0;
      goto LAB_23e894f71;
    }
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  pcVar16 = (code *)0x0;
  pcStack_d0 = (code *)0x0;
  pcVar17 = (code *)0x0;
  plVar11 = (longlong *)0x0;
  uVar21 = 0x143;
  pcStack_c8 = (code *)0x0;
LAB_23e894f71:
  plVar13 = plStack_88;
  plVar15 = DAT_23ed6a4f8;
  if (plStack_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar21;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar3 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar13 = plVar15;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  else if ((longlong *)plStack_88[3] != plVar5) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar19 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar21;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar3 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    plVar13 = plVar15;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  plStack_88 = plVar13;
  FUN_23e8bba40(plVar5,"oooooooooo",plVar1,plVar2,pcVar9,pcVar10,pcStack_e0,pcVar16,plVar11,
                pcStack_c8,pcVar17,pcStack_d0);
  if (_DAT_23eede618 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede618 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar12 + 0x28);
  plVar15 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar15 = plStack_88;
  uVar6 = auStack_98._8_8_;
  uVar14 = auStack_98._0_8_;
  plVar5[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((pcVar9 != (code *)0x0) &&
     (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
    (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
  }
  if ((pcVar10 != (code *)0x0) &&
     (*(longlong *)pcVar10 = *(longlong *)pcVar10 + -1, *(longlong *)pcVar10 == 0)) {
    (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
  }
  if ((pcStack_e0 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_e0, *(longlong *)pcStack_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_e0 + 8) + 0x30))(pcStack_e0);
  }
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((pcStack_c8 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))(pcStack_c8);
  }
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
  }
  if ((pcStack_d0 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_d0 + 8) + 0x30))(pcStack_d0);
  }
  auStack_98 = CONCAT88(uVar6,uVar14);
  lVar12 = *plVar1;
  *plVar1 = lVar12 + -1;
  plStack_88 = plVar15;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,plStack_88);
  return (code *)0x0;
}
