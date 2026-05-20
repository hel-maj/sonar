/* ===== 23e2c6870 ui.home_tab:289 ===== */
/* ghidra_name=FUN_23e2c6870 entry=23e2c6870 size=23666 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2c6870(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  code *pcVar17;
  longlong lVar18;
  undefined1 auVar19 [8];
  undefined8 uVar20;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong **pplStack_e8;
  longlong *plStack_c8;
  code *pcStack_c0;
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  longlong *plStack_98;
  code *pcStack_90;
  code *pcStack_88;
  undefined1 auStack_78 [8];
  code *pcStack_70;
  code *pcStack_68;
  
  plVar6 = _DAT_23eeb02d8;
  param_3 = (longlong *)*param_3;
  pcStack_68 = (code *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  pcStack_70 = (code *)0x0;
  if (_DAT_23eeb02d8 == (longlong *)0x0) {
LAB_23e2c68d5:
    _DAT_23eeb02d8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb02d0,DAT_23eeb0380,0x78);
  }
  else {
    lVar10 = *_DAT_23eeb02d8;
    if (1 < lVar10) {
      *_DAT_23eeb02d8 = lVar10 + -1;
      goto LAB_23e2c68d5;
    }
    if (_DAT_23eeb02d8[2] != 0) {
      *_DAT_23eeb02d8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e2c68d5;
    }
  }
  plVar2 = _DAT_23eeb02d8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeb02d8 + 9;
  lVar18 = *(longlong *)(lVar10 + 8);
  _DAT_23eeb02d8[0xf] = lVar18;
  *(longlong **)(lVar10 + 8) = plVar6;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar20 = _DAT_23eead900;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(param_3,uVar20);
  if (plVar6 == (longlong *)0x0) {
LAB_23e2c6e40:
    pcStack_68 = *(code **)(param_1 + 0x70);
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_70 = *(code **)(param_1 + 0x68);
    iVar5 = 0x125;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c6e6f;
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eeadd18);
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))();
  }
  if (plVar7 == (longlong *)0x0) goto LAB_23e2c6e40;
  iVar5 = FUN_23a35f020();
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))();
  }
  if (iVar5 == -1) goto LAB_23e2c6e40;
  if (iVar5 == 0) {
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
    lVar10 = _DAT_23eeadd20;
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x126;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
    }
    else {
      *(undefined4 *)(plVar2 + 5) = 0x126;
      plVar7 = (longlong *)
               FUN_23e915840(param_1,plVar6,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18));
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      if (plVar7 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar5 = 0x126;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar6 = (longlong *)0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
      }
      else {
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
        if (plVar6 == (longlong *)0x0) goto LAB_23e2c9158;
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eead9b8);
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))();
        }
        plVar6 = _DAT_23eeadca8;
        if (plVar8 != (longlong *)0x0) {
          lVar10 = *(longlong *)(param_1 + 0x10);
          pcVar17 = *(code **)(lVar10 + 0xe28);
          if (pcVar17 == (code *)0x0) {
            pcVar17 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar18 = *(longlong *)(pcVar17 + 0x18);
            *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
            *(longlong *)(lVar10 + 0xe28) = lVar18;
            *(longlong *)pcVar17 = 1;
          }
          pcVar16 = _PyRuntime_exref;
          *(undefined1 (*) [16])(pcVar17 + 0x20) = (undefined1  [16])0x0;
          lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
          lVar18 = *(longlong *)(pcVar17 + -8);
          puVar1 = *(undefined8 **)(lVar10 + 8);
          *puVar1 = pcVar17 + -0x10;
          *(longlong *)(pcVar17 + -0x10) = lVar10;
          *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
          *(code **)(lVar10 + 8) = pcVar17 + -0x10;
          *plVar6 = *plVar6 + 1;
          *(longlong **)(pcVar17 + 0x18) = plVar6;
          plVar9 = (longlong *)FUN_23e8f6530();
          if (plVar9 != (longlong *)0x0) {
            plVar7 = (longlong *)&DAT_23ed6a4c0;
            plVar6 = DAT_23ed6a4c0;
            pcVar16 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e2c9573;
            goto LAB_23e2c6b42;
          }
          FUN_23e915740(param_1,auStack_78,DAT_23eeadd28);
          goto LAB_23e2c9379;
        }
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar5 = 0x127;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcStack_70 = *(code **)(param_1 + 0x68);
      }
    }
LAB_23e2c6ef9:
    pcVar17 = pcStack_68;
    auStack_b8._8_8_ = pcStack_70;
    auStack_b8._0_8_ = auStack_78;
    pcStack_68 = (code *)0x0;
    auStack_78 = (undefined1  [8])0x0;
    pcStack_70 = (code *)0x0;
    apcStack_a8[0] = pcVar17;
    plVar14 = *(longlong **)(param_1 + 0x138);
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
    pcVar16 = DAT_23ed6a4f8;
    if (pcVar17 == (code *)0x0) {
      if (iVar5 == 0) {
        iVar5 = (int)plVar2[5];
      }
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        pcVar17 = apcStack_a8[0];
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        pcVar17 = (code *)0x0;
      }
      pcVar15 = _PyRuntime_exref;
      *(longlong *)(pcVar16 + 0x10) = 0;
      *(longlong **)(pcVar16 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar10 = *(longlong *)(pcVar15 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(int *)(pcVar16 + 0x24) = iVar5;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar18 = *(longlong *)(pcVar16 + -8);
      puVar1 = *(undefined8 **)(lVar10 + 8);
      *puVar1 = pcVar16 + -0x10;
      *(longlong *)(pcVar16 + -0x10) = lVar10;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
      *(code **)(lVar10 + 8) = pcVar16 + -0x10;
      pcVar15 = pcVar16;
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
      }
    }
    else {
      pcVar15 = apcStack_a8[0];
      if (iVar5 != 0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar15 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar15;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar15 = _PyRuntime_exref;
        *(longlong **)(pcVar16 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        lVar10 = *(longlong *)(pcVar15 + 0x1f8);
        *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
        *(int *)(pcVar16 + 0x24) = iVar5;
        lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar16 + -8);
        puVar1 = *(undefined8 **)(lVar10 + 8);
        *puVar1 = pcVar16 + -0x10;
        *(longlong *)(pcVar16 + -0x10) = lVar10;
        *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
        *(code **)(lVar10 + 8) = pcVar16 + -0x10;
        *(code **)(pcVar16 + 0x10) = pcVar17;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        pcVar15 = pcVar16;
        if ((apcStack_a8[0] != (code *)0x0) &&
           (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
           *(longlong *)apcStack_a8[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
        }
      }
    }
    apcStack_a8[0] = pcVar15;
    pcVar17 = _Py_NoneStruct_exref;
    if (((code *)auStack_b8._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_b8._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
    }
    plVar7 = *(longlong **)(auStack_b8._8_8_ + 0x28);
    if (apcStack_a8[0] == pcVar17) {
      pcVar16 = (code *)0x0;
    }
    else {
      pcVar16 = apcStack_a8[0];
      if (apcStack_a8[0] != (code *)0x0) {
        *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
      }
    }
    *(code **)(auStack_b8._8_8_ + 0x28) = pcVar16;
    if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    plVar7 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
    if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
      (**(code **)(plVar7[1] + 0x30))();
    }
    *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
    if (*(longlong *)auStack_b8._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_a8[0] != (code *)0x0) &&
       (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
       *(longlong *)apcStack_a8[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
    }
    apcStack_a8[0] = (code *)0x0;
    auStack_b8 = (undefined1  [16])0x0;
    iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                          *(undefined8 *)PyExc_Exception_exref);
    if (iVar5 == 0) {
      pcVar16 = *(code **)(param_1 + 0x138);
      pcStack_70 = pcVar16;
      if ((pcVar16 == pcVar17) || (pcVar16 == (code *)0x0)) {
        pcVar17 = (code *)0x0;
        iVar5 = 0x123;
        auVar19 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
        pcVar15 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar16 = *(code **)(param_1 + 0x138);
        *(longlong *)auVar19 = *(longlong *)auVar19 + 1;
        goto LAB_23e2c8965;
      }
      auVar19 = *(undefined1 (*) [8])(pcVar16 + 8);
      pcVar17 = *(code **)(pcVar16 + 0x28);
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      *(longlong *)auVar19 = *(longlong *)auVar19 + 1;
      iVar5 = 0;
      pcVar15 = pcVar16;
      if (pcVar17 == (code *)0x0) {
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
      else {
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        if (*(longlong **)(pcVar17 + 0x18) == plVar2) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar17 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar14;
      }
LAB_23e2c7660:
      pcStack_68 = (code *)0x0;
      _auStack_78 = (undefined1  [16])0x0;
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
      if (*(longlong *)pcVar16 == 0) {
        (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))();
      }
      pcStack_70 = pcVar15;
      auStack_78 = auVar19;
      if (pcVar17 == (code *)0x0) {
        pcStack_68 = (code *)0x0;
        if (iVar5 == 0) {
          iVar5 = (int)plVar2[5];
        }
LAB_23e2c89b6:
        pcVar17 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          pcVar16 = pcStack_68;
        }
        else {
          pcVar16 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar16;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          pcVar16 = (code *)0x0;
        }
        pcVar15 = _PyRuntime_exref;
        *(longlong *)(pcVar17 + 0x10) = 0;
        *(longlong **)(pcVar17 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        lVar10 = *(longlong *)(pcVar15 + 0x1f8);
        *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
        lVar10 = *(longlong *)(lVar10 + 0x10);
        *(int *)(pcVar17 + 0x24) = iVar5;
        lVar10 = *(longlong *)(lVar10 + 0x2e8);
        lVar18 = *(longlong *)(pcVar17 + -8);
        puVar1 = *(undefined8 **)(lVar10 + 8);
        *puVar1 = pcVar17 + -0x10;
        *(longlong *)(pcVar17 + -0x10) = lVar10;
        *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
        *(code **)(lVar10 + 8) = pcVar17 + -0x10;
        if ((pcVar16 != (code *)0x0) &&
           (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))();
        }
        goto LAB_23e2c7759;
      }
LAB_23e2c769e:
      pcVar16 = DAT_23ed6a4f8;
      if (*(longlong **)(pcVar17 + 0x18) != plVar2) {
        if (iVar5 == 0) {
          iVar5 = (int)plVar2[5];
        }
        pcStack_68 = pcVar17;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar15 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar15;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar15 = _PyRuntime_exref;
        *(longlong **)(pcVar16 + 0x18) = plVar2;
        *plVar2 = *plVar2 + 1;
        lVar10 = *(longlong *)(pcVar15 + 0x1f8);
        *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
        *(int *)(pcVar16 + 0x24) = iVar5;
        lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
        lVar18 = *(longlong *)(pcVar16 + -8);
        puVar1 = *(undefined8 **)(lVar10 + 8);
        *puVar1 = pcVar16 + -0x10;
        *(longlong *)(pcVar16 + -0x10) = lVar10;
        *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
        *(code **)(lVar10 + 8) = pcVar16 + -0x10;
        *(code **)(pcVar16 + 0x10) = pcVar17;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        pcVar17 = pcVar16;
        if ((pcStack_68 != (code *)0x0) &&
           (*(longlong *)pcStack_68 = *(longlong *)pcStack_68 + -1, *(longlong *)pcStack_68 == 0)) {
          (**(code **)(*(longlong *)(pcStack_68 + 8) + 0x30))();
        }
      }
LAB_23e2c7759:
      pcStack_68 = pcVar17;
      FUN_23e8bba40(plVar2,"ooooooooooooooo",param_3,plVar8,plVar6,plStack_138,plStack_110,
                    plStack_f0,plStack_118,plStack_120,plStack_128,plStack_130,plStack_100,
                    plStack_108,0,pplStack_e8,plStack_f8);
      if (_DAT_23eeb02d8 == plVar2) {
        *plVar2 = *plVar2 + -1;
        if (*plVar2 == 0) {
          (**(code **)(plVar2[1] + 0x30))(plVar2);
        }
        _DAT_23eeb02d8 = (longlong *)0x0;
      }
      lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar2 = *(longlong **)(lVar10 + 0x28);
      plVar7 = (longlong *)plVar2[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
      *(undefined4 *)(plVar2 + 8) = 0xffffffff;
      if (plVar7 != (longlong *)0x0) {
        plVar2[2] = 0;
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))();
        }
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      pcVar16 = pcStack_68;
      plVar2[0xf] = 0;
      auVar19 = auStack_78;
      pcVar17 = pcStack_70;
      _auStack_78 = (undefined1  [16])0x0;
      pcStack_68 = (code *)0x0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      if ((plStack_138 != (longlong *)0x0) &&
         (lVar10 = *plStack_138, *plStack_138 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_138[1] + 0x30))(plStack_138);
      }
      if ((plStack_110 != (longlong *)0x0) &&
         (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_110[1] + 0x30))(plStack_110);
      }
      if ((plStack_f0 != (longlong *)0x0) &&
         (lVar10 = *plStack_f0, *plStack_f0 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
      }
      if ((plStack_118 != (longlong *)0x0) &&
         (lVar10 = *plStack_118, *plStack_118 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_118[1] + 0x30))(plStack_118);
      }
      if ((plStack_120 != (longlong *)0x0) &&
         (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_120[1] + 0x30))(plStack_120);
      }
      if ((plStack_128 != (longlong *)0x0) &&
         (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_128[1] + 0x30))(plStack_128);
      }
      if ((plStack_130 != (longlong *)0x0) &&
         (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_130[1] + 0x30))(plStack_130);
      }
      if ((plStack_100 != (longlong *)0x0) &&
         (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_100[1] + 0x30))(plStack_100);
      }
      if ((plStack_108 != (longlong *)0x0) &&
         (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_108[1] + 0x30))(plStack_108);
      }
      if ((pplStack_e8 != (longlong **)0x0) &&
         (lVar10 = (longlong)*pplStack_e8, *pplStack_e8 = (longlong *)(lVar10 + -1),
         lVar10 + -1 == 0)) {
        (**(code **)((longlong)pplStack_e8[1] + 0x30))(pplStack_e8);
      }
      if ((plStack_f8 != (longlong *)0x0) &&
         (lVar10 = *plStack_f8, *plStack_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
        (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
      }
      lVar10 = *param_3;
      *param_3 = lVar10 + -1;
      pcStack_68 = pcVar16;
      auStack_78 = auVar19;
      pcStack_70 = pcVar17;
      if (lVar10 + -1 == 0) {
        (**(code **)(param_3[1] + 0x30))(param_3);
      }
      FUN_23a33aa70(param_1,auStack_78,pcStack_70,pcStack_68);
      return (code *)0x0;
    }
    plVar7 = *(longlong **)(param_1 + 0x138);
    *plVar7 = *plVar7 + 1;
    lVar10 = FUN_23e8f6a70();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,auStack_78,DAT_23eeadcf8);
      auVar19 = auStack_78;
      pcVar17 = pcStack_68;
      pcVar15 = pcStack_70;
LAB_23e2c8920:
      pcStack_68 = (code *)0x0;
      _auStack_78 = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      pcVar16 = *(code **)(param_1 + 0x138);
      iVar5 = 0x175;
LAB_23e2c8965:
      *(longlong **)(param_1 + 0x138) = plVar14;
      if (pcVar16 != (code *)0x0) goto LAB_23e2c7660;
      pcStack_70 = pcVar15;
      auStack_78 = auVar19;
      pcStack_68 = pcVar17;
      if (pcVar17 == (code *)0x0) goto LAB_23e2c89b6;
      goto LAB_23e2c769e;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eeade28);
    plVar9 = _DAT_23eeade58;
    if (plVar11 == (longlong *)0x0) {
      auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar17 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar15 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c8920;
    }
    lVar10 = *(longlong *)(param_1 + 0x10);
    plVar12 = *(longlong **)(lVar10 + 0xe20);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar18 = plVar12[3];
      *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
      *(longlong *)(lVar10 + 0xe20) = lVar18;
      *plVar12 = 1;
    }
    pcVar16 = _PyRuntime_exref;
    plVar12[4] = 0;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = plVar12[-1];
    puVar1 = *(undefined8 **)(lVar10 + 8);
    *puVar1 = plVar12 + -2;
    plVar12[-2] = lVar10;
    plVar12[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar10 + 8) = plVar12 + -2;
    plVar13 = DAT_23ed6a4c0;
    *plVar9 = *plVar9 + 1;
    plVar12[3] = (longlong)plVar9;
    pcVar16 = DAT_23ed6cd28;
    if (plVar13 != (longlong *)0x0) {
LAB_23e2c7141:
      pcStack_c0 = pcVar16;
      plStack_c8 = plVar7;
      lVar10 = FUN_23e94ed00(param_1,plVar13,&plStack_c8);
      if (lVar10 == 0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar12 = *plVar12 + -1;
        auVar19 = auStack_78;
        pcVar17 = pcStack_68;
        pcVar15 = pcStack_70;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          auVar19 = auStack_78;
          pcVar17 = pcStack_68;
          pcVar15 = pcStack_70;
        }
      }
      else {
        plVar12[4] = lVar10;
        lVar10 = PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (lVar10 == 0) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar11 = *plVar11 + -1;
          auVar19 = auStack_78;
          pcVar17 = pcStack_68;
          pcVar15 = pcStack_70;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            auVar19 = auStack_78;
            pcVar17 = pcStack_68;
            pcVar15 = pcStack_70;
          }
          goto LAB_23e2c8920;
        }
        lVar18 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(lVar18 + 0xe18);
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
        }
        else {
          lVar3 = plVar9[3];
          *(int *)(lVar18 + 0xeb8) = *(int *)(lVar18 + 0xeb8) + -1;
          *(longlong *)(lVar18 + 0xe18) = lVar3;
          *plVar9 = 1;
        }
        lVar18 = *(longlong *)
                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = plVar9[-1];
        puVar1 = *(undefined8 **)(lVar18 + 8);
        *puVar1 = plVar9 + -2;
        plVar9[-2] = lVar18;
        plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar1;
        *(longlong **)(lVar18 + 8) = plVar9 + -2;
        uVar20 = _DAT_23eeade60;
        plVar9[3] = lVar10;
        plVar12 = (longlong *)FUN_23e8d7870(param_1,uVar20);
        *(undefined4 *)(plVar2 + 5) = 0x175;
        plVar13 = (longlong *)FUN_23a334c60(param_1,plVar11,plVar9,plVar12);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar13 != (longlong *)0x0) {
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar2 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar14;
          if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
            (**(code **)(plVar2[1] + 0x30))();
          }
          goto LAB_23e2c730b;
        }
        auVar19 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar15 = *(code **)(param_1 + 0x68);
      }
      goto LAB_23e2c8920;
    }
    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    plVar9 = plVar7;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
      DAT_23ed6a4c0 = plVar13;
      goto LAB_23e2c7141;
    }
LAB_23e2c9560:
    do {
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e2c9573:
      plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    } while (plVar6 == (longlong *)0x0);
    *plVar6 = *plVar6 + 1;
    *plVar7 = (longlong)plVar6;
LAB_23e2c6b42:
    plStack_98 = plVar9;
    pcStack_90 = pcVar16;
    lVar10 = FUN_23e94ed00(param_1,plVar6,&plStack_98);
    if (lVar10 == 0) {
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c9379:
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
      if (*(longlong *)pcVar17 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
      }
LAB_23e2c9181:
      iVar5 = 0x127;
LAB_23e2c6e6f:
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    *(longlong *)(pcVar17 + 0x20) = lVar10;
    plVar6 = _DAT_23eeadd30;
    *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
    *(longlong **)(pcVar17 + 0x28) = plVar6;
    plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar17);
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
    if (*(longlong *)pcVar17 == 0) {
      (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
    }
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      goto LAB_23e2c9181;
    }
    *(undefined4 *)(plVar2 + 5) = 0x127;
    plVar7 = (longlong *)FUN_23e914090(param_1,plVar8,plVar6);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) {
LAB_23e2c9158:
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c9181;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb88);
    lVar10 = _DAT_23eeadd38;
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x128;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x128;
    plVar7 = (longlong *)FUN_23e915840(param_1,plVar6,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18))
    ;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x128;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
    lVar10 = _DAT_23eeadd38;
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x129;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x129;
    plVar7 = (longlong *)FUN_23e915840(param_1,plVar6,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18))
    ;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plVar8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x129;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadba8);
    lVar10 = _DAT_23eeadd38;
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x12a;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x12a;
    plVar7 = (longlong *)FUN_23e915840(param_1,plVar6,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18))
    ;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plVar8 = (longlong *)0x0;
      iVar5 = 0x12a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar8 = (longlong *)0x0;
    lVar10 = *(longlong *)_Py_NoneStruct_exref;
LAB_23e2c6d58:
    pcVar17 = _Py_NoneStruct_exref;
    *(longlong *)_Py_NoneStruct_exref = lVar10 + 1;
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar6 = *(longlong **)(lVar10 + 0x28);
    plVar2 = (longlong *)plVar6[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
    if (plVar2 != (longlong *)0x0) {
      plVar6[2] = 0;
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        (**(code **)(plVar2[1] + 0x30))();
      }
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar6[0xf] = 0;
    if ((plVar8 == (longlong *)0x0) || (*plVar8 = *plVar8 + -1, *plVar8 != 0)) goto LAB_23e2c6dfb;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    plStack_f8 = (longlong *)0x0;
  }
  else {
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead900);
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x12e;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eeadd40);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar8 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x12e;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c6ef9;
    }
    iVar5 = FUN_23a35f020();
    if (iVar5 == -1) {
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      iVar5 = 0x12f;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c93d7:
      plStack_f8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    if (iVar5 == 0) {
      plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
      lVar10 = _DAT_23eeadd48;
      if (plVar6 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        iVar5 = 0x130;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar6 = (longlong *)0x0;
        goto LAB_23e2c6ef9;
      }
      *(undefined4 *)(plVar2 + 5) = 0x130;
      plVar7 = (longlong *)
               FUN_23e915840(param_1,plVar6,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18));
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      if (plVar7 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar5 = 0x130;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_138 = (longlong *)0x0;
        goto LAB_23e2c6ef9;
      }
      lVar10 = *plVar7;
      *plVar7 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
      if (plVar6 == (longlong *)0x0) {
LAB_23e2c9699:
        pcStack_68 = *(code **)(param_1 + 0x70);
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c96c2:
        iVar5 = 0x131;
        goto LAB_23e2c93d7;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eead9b8);
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      plVar6 = _DAT_23eeadca8;
      if (plVar14 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        iVar5 = 0x131;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar6 = (longlong *)0x0;
        goto LAB_23e2c6ef9;
      }
      lVar10 = *(longlong *)(param_1 + 0x10);
      pcVar17 = *(code **)(lVar10 + 0xe28);
      if (pcVar17 == (code *)0x0) {
        pcVar17 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar18 = *(longlong *)(pcVar17 + 0x18);
        *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
        *(longlong *)(lVar10 + 0xe28) = lVar18;
        *(longlong *)pcVar17 = 1;
      }
      pcVar16 = _PyRuntime_exref;
      *(undefined1 (*) [16])(pcVar17 + 0x20) = (undefined1  [16])0x0;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = *(longlong *)(pcVar17 + -8);
      puVar1 = *(undefined8 **)(lVar10 + 8);
      *puVar1 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar10;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
      *(code **)(lVar10 + 8) = pcVar17 + -0x10;
      *plVar6 = *plVar6 + 1;
      *(longlong **)(pcVar17 + 0x18) = plVar6;
      plVar9 = (longlong *)FUN_23e8f6920();
      pcVar16 = DAT_23ed6cd28;
      if (plVar9 == (longlong *)0x0) {
        FUN_23e915740(param_1,auStack_78,DAT_23eeadd50);
LAB_23e2c9b9c:
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))();
        }
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
        if (*(longlong *)pcVar17 == 0) {
          (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
        }
        goto LAB_23e2c96c2;
      }
      plVar7 = (longlong *)&DAT_23ed6a4c0;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar6 == (longlong *)0x0) goto LAB_23e2c9560;
        *plVar6 = *plVar6 + 1;
        DAT_23ed6a4c0 = plVar6;
      }
      pcStack_90 = pcVar16;
      plStack_98 = plVar9;
      lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
      if (lVar10 == 0) {
        pcStack_68 = *(code **)(param_1 + 0x70);
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2c9b9c;
      }
      *(longlong *)(pcVar17 + 0x20) = lVar10;
      plVar6 = _DAT_23eeadd30;
      *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
      *(longlong **)(pcVar17 + 0x28) = plVar6;
      plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar17);
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
      if (*(longlong *)pcVar17 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
      }
      if (plVar6 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          FUN_23a334bc0();
        }
        goto LAB_23e2c96c2;
      }
      *(undefined4 *)(plVar2 + 5) = 0x131;
      plVar7 = (longlong *)FUN_23e914090(param_1,plVar14,plVar6);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      if (plVar7 == (longlong *)0x0) goto LAB_23e2c9699;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      lVar10 = *(longlong *)_Py_NoneStruct_exref;
      goto LAB_23e2c6d58;
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead900);
    if (plVar6 == (longlong *)0x0) {
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c9491:
      iVar5 = 0x135;
      goto LAB_23e2c93d7;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eeadd58);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      iVar5 = 0x135;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    iVar5 = FUN_23a35f020();
    lVar10 = *plVar9 + -1;
    if (iVar5 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = lVar10;
      if (lVar10 == 0) {
        (**(code **)(plVar9[1] + 0x30))();
      }
      goto LAB_23e2c9491;
    }
    *plVar9 = lVar10;
    if (lVar10 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (iVar5 == 0) {
      plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
      if (plVar6 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plStack_f8 = (longlong *)0x0;
        iVar5 = 0x139;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar6 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0x139;
        plVar9 = (longlong *)FUN_23e915840(param_1,plVar6,_DAT_23eeada60);
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))();
        }
        if (plVar9 != (longlong *)0x0) {
          lVar10 = *plVar9;
          *plVar9 = lVar10 + -1;
          if (lVar10 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
          if (plVar6 == (longlong *)0x0) {
LAB_23e2c9901:
            pcStack_68 = *(code **)(param_1 + 0x70);
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eead9b8);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))();
            }
            plVar6 = _DAT_23eeadca8;
            if (plVar14 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              pcStack_68 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_f8 = (longlong *)0x0;
              pplStack_e8 = (longlong **)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              iVar5 = 0x13a;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar6 = (longlong *)0x0;
              goto LAB_23e2c6ef9;
            }
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar11 = *(longlong **)(lVar10 + 0xe28);
            if (plVar11 == (longlong *)0x0) {
              plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
            }
            else {
              lVar18 = plVar11[3];
              *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
              *(longlong *)(lVar10 + 0xe28) = lVar18;
              *plVar11 = 1;
            }
            pcVar17 = _PyRuntime_exref;
            *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
            lVar18 = plVar11[-1];
            puVar1 = *(undefined8 **)(lVar10 + 8);
            *puVar1 = plVar11 + -2;
            plVar11[-2] = lVar10;
            plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
            *(longlong **)(lVar10 + 8) = plVar11 + -2;
            *plVar6 = *plVar6 + 1;
            plVar11[3] = (longlong)plVar6;
            plVar9 = (longlong *)FUN_23e8f6530();
            pcVar16 = DAT_23ed6cd28;
            if (plVar9 == (longlong *)0x0) {
              FUN_23e915740(param_1,auStack_78,DAT_23eeadd28);
            }
            else {
              pcVar17 = (code *)&DAT_23ed6a4c0;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar6 == (longlong *)0x0) goto LAB_23e2c9560;
                *plVar6 = *plVar6 + 1;
                DAT_23ed6a4c0 = plVar6;
              }
              pcStack_90 = pcVar16;
              plStack_98 = plVar9;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
              if (lVar10 != 0) {
                plVar11[4] = lVar10;
                pcVar17 = PyUnicode_Join_exref;
                plVar6 = _DAT_23eeadd30;
                *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
                plVar11[5] = (longlong)plVar6;
                plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar6 != (longlong *)0x0) {
                  *(undefined4 *)(plVar2 + 5) = 0x13a;
                  plVar7 = (longlong *)FUN_23e914090(param_1,plVar14,plVar6);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0();
                  }
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    FUN_23a334bc0();
                  }
                  if (plVar7 != (longlong *)0x0) goto LAB_23e2c7eeb;
                  goto LAB_23e2c9901;
                }
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                pcStack_68 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0();
                }
                goto LAB_23e2c992a;
              }
              pcStack_68 = *(code **)(param_1 + 0x70);
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              FUN_23a334bc0();
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0();
            }
          }
LAB_23e2c992a:
          iVar5 = 0x13a;
          goto LAB_23e2c93d7;
        }
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        pcStack_68 = *(code **)(param_1 + 0x70);
        plVar6 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar5 = 0x139;
        plStack_f8 = (longlong *)0x0;
        pplStack_e8 = (longlong **)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_138 = (longlong *)0x0;
      }
      goto LAB_23e2c6ef9;
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plStack_f8 = (longlong *)0x0;
      iVar5 = 0x136;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x136;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar6,_DAT_23eeada60);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plVar6 = (longlong *)0x0;
      iVar5 = 0x136;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    lVar10 = *plVar9;
    *plVar9 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    plVar6 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb78);
    if (plVar6 == (longlong *)0x0) {
LAB_23e2ca038:
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ca061:
      iVar5 = 0x137;
      goto LAB_23e2c93d7;
    }
    plVar14 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eead9b8);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
    plVar6 = _DAT_23eeadca8;
    if (plVar14 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x137;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar6 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    lVar10 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(lVar10 + 0xe28);
    if (plVar11 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar18 = plVar11[3];
      *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
      *(longlong *)(lVar10 + 0xe28) = lVar18;
      *plVar11 = 1;
    }
    pcVar17 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = plVar11[-1];
    puVar1 = *(undefined8 **)(lVar10 + 8);
    *puVar1 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
    *plVar6 = *plVar6 + 1;
    plVar11[3] = (longlong)plVar6;
    plVar9 = (longlong *)FUN_23e8f6680();
    pcVar16 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) {
      FUN_23e915740(param_1,auStack_78,DAT_23eeadd68);
LAB_23e2ca437:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23e2ca061;
    }
    pcVar17 = (code *)&DAT_23ed6a4c0;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar6 == (longlong *)0x0) goto LAB_23e2c9560;
      *plVar6 = *plVar6 + 1;
      DAT_23ed6a4c0 = plVar6;
    }
    pcStack_90 = pcVar16;
    plStack_98 = plVar9;
    lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
    if (lVar10 == 0) {
      pcStack_68 = *(code **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2ca437;
    }
    plVar11[4] = lVar10;
    pcVar17 = PyUnicode_Join_exref;
    plVar6 = _DAT_23eeadd30;
    *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
    plVar11[5] = (longlong)plVar6;
    plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      FUN_23a334bc0();
    }
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23e2ca061;
    }
    *(undefined4 *)(plVar2 + 5) = 0x137;
    plVar7 = (longlong *)FUN_23e914090(param_1,plVar14,plVar6);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      FUN_23a334bc0();
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      FUN_23a334bc0();
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23e2ca038;
LAB_23e2c7eeb:
    pplStack_e8 = &plStack_98;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0(plVar7);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x13d;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x13d;
    plVar6 = (longlong *)FUN_23e9557e0(param_1,plVar7);
    lVar10 = *plVar7;
    *plVar7 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (plVar6 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x13d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c6ef9;
    }
    iVar5 = FUN_23a35f020();
    if (iVar5 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar5 = 0x13e;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c6ef9;
    }
    if (iVar5 != 0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eeadd80);
      if (plVar7 == (longlong *)0x0) {
LAB_23e2ca965:
        pcStack_68 = *(code **)(param_1 + 0x70);
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_70 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ca98c:
        uVar20 = 0x141;
LAB_23e2ca991:
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_f0 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar2 + 5) = 0x141;
        plVar9 = (longlong *)FUN_23e94bb80(param_1,plVar7);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0();
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e2ca965;
        iVar5 = FUN_23a35f020();
        lVar10 = *plVar9 + -1;
        if (iVar5 == -1) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = lVar10;
          if (lVar10 == 0) {
            FUN_23a334bc0();
          }
          goto LAB_23e2ca98c;
        }
        *plVar9 = lVar10;
        if (lVar10 == 0) {
          FUN_23a334bc0(plVar9);
        }
        if (iVar5 != 0) {
          lVar10 = FUN_23e8f67d0();
          if (lVar10 == 0) {
            FUN_23e915740(param_1,auStack_78);
          }
          else {
            plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eeadd98);
            if (plVar7 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              pcStack_68 = *(code **)(param_1 + 0x70);
              uVar20 = 0x142;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_108 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_f0 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plStack_110 = (longlong *)0x0;
              goto LAB_23e2ca9dc;
            }
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar6,_DAT_23eeadda0);
            if (plVar9 != (longlong *)0x0) {
              *(undefined4 *)(plVar2 + 5) = 0x142;
              plVar14 = (longlong *)FUN_23e9557e0(param_1,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                FUN_23a334bc0();
              }
              if (plVar14 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0x142;
                plStack_138 = (longlong *)FUN_23e914090(param_1,plVar7);
                lVar10 = *plVar7;
                *plVar7 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  FUN_23a334bc0();
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0();
                }
                if (plStack_138 != (longlong *)0x0) goto LAB_23e2c80d9;
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                pcStack_68 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e2cb455;
              }
            }
            pcStack_68 = *(code **)(param_1 + 0x70);
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            lVar10 = *plVar7;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar7 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              FUN_23a334bc0();
            }
          }
LAB_23e2cb455:
          uVar20 = 0x142;
          goto LAB_23e2ca991;
        }
        lVar10 = FUN_23e8f67d0();
        if (lVar10 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eeadd90);
          plStack_138 = (longlong *)0x0;
LAB_23e2cb4ca:
          uVar20 = 0x144;
          plStack_108 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
        }
        else {
          *(undefined4 *)(plVar2 + 5) = 0x144;
          plStack_138 = (longlong *)FUN_23e915840(param_1,lVar10,_DAT_23eeadd98);
          if (plStack_138 == (longlong *)0x0) {
            pcStack_68 = *(code **)(param_1 + 0x70);
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2cb4ca;
          }
LAB_23e2c80d9:
          *(undefined4 *)(plVar2 + 5) = 0x147;
          plStack_110 = (longlong *)FUN_23e91bfe0(param_1,plStack_138,_DAT_23eeaddb0);
          lVar10 = _DAT_23eeaddc0;
          if (plStack_110 == (longlong *)0x0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            uVar20 = 0x147;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_108 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            plStack_130 = (longlong *)0x0;
            plStack_128 = (longlong *)0x0;
            plStack_120 = (longlong *)0x0;
            plStack_118 = (longlong *)0x0;
            plStack_f0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0x14a;
            plStack_f0 = (longlong *)
                         FUN_23e915840(param_1,plStack_110,_DAT_23eeaddb8,
                                       *(undefined8 *)(lVar10 + 0x18));
            if (plStack_f0 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_70 = *(code **)(param_1 + 0x68);
              pcStack_68 = *(code **)(param_1 + 0x70);
              uVar20 = 0x14a;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_108 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb88);
              if (plVar7 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_70 = *(code **)(param_1 + 0x68);
                pcStack_68 = *(code **)(param_1 + 0x70);
                uVar20 = 0x14c;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_108 = (longlong *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_120 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(plVar2 + 5) = 0x14c;
                plVar9 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eeada60);
                lVar10 = *plVar7;
                *plVar7 = lVar10 + -1;
                if (lVar10 + -1 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar9 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_70 = *(code **)(param_1 + 0x68);
                  pcStack_68 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_108 = (longlong *)0x0;
                  plStack_100 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  uVar20 = 0x14c;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plStack_118 = (longlong *)0x0;
                }
                else {
                  lVar10 = *plVar9;
                  *plVar9 = lVar10 + -1;
                  if (lVar10 + -1 == 0) {
                    FUN_23a334bc0(plVar9);
                  }
                  lVar10 = FUN_23e8f67d0();
                  if (lVar10 == 0) {
                    FUN_23e915740(param_1,auStack_78,DAT_23eeadd90);
                  }
                  else {
                    plVar7 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eeaddc8);
                    if (plVar7 == (longlong *)0x0) {
                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_70 = *(code **)(param_1 + 0x68);
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      uVar20 = 0x14f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_108 = (longlong *)0x0;
                      plStack_100 = (longlong *)0x0;
                      plStack_130 = (longlong *)0x0;
                      plStack_128 = (longlong *)0x0;
                      plStack_118 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plStack_120 = (longlong *)0x0;
                      goto LAB_23e2ca9dc;
                    }
                    lVar10 = *(longlong *)(DAT_23eeae258 + 0x20);
                    if (*(char *)(lVar10 + 10) == '\0') {
                      plVar9 = (longlong *)FUN_23a37a020(DAT_23eeae258,DAT_23eeaddd0);
                      if (plVar9 == (longlong *)0x0) goto LAB_23e2cc3cb;
                      lVar18 = *plVar9;
LAB_23e2cc3c2:
                      if (lVar18 == 0) goto LAB_23e2cc3cb;
LAB_23e2c82a2:
                      plVar9 = (longlong *)FUN_23e8bc2f0(lVar18,_DAT_23eeaddd8);
                      if (plVar9 != (longlong *)0x0) {
                        *(undefined4 *)(plVar2 + 5) = 0x14f;
                        plStack_118 = (longlong *)FUN_23e914090(param_1,plVar7,plVar9);
                        lVar10 = *plVar7;
                        *plVar7 = lVar10 + -1;
                        if (lVar10 + -1 == 0) {
                          FUN_23a334bc0();
                        }
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plStack_118 == (longlong *)0x0) {
                          pcStack_68 = *(code **)(param_1 + 0x70);
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e2cc30e;
                        }
                        plStack_120 = (longlong *)FUN_23e8c6640(plStack_138,plStack_118);
                        if (plStack_120 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_70 = *(code **)(param_1 + 0x68);
                          pcStack_68 = *(code **)(param_1 + 0x70);
                          uVar20 = 0x150;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_108 = (longlong *)0x0;
                          plStack_100 = (longlong *)0x0;
                          plStack_130 = (longlong *)0x0;
                          plStack_128 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          *(undefined4 *)(plVar2 + 5) = 0x152;
                          plVar7 = (longlong *)FUN_23e91bfe0(param_1,plStack_120);
                          if (plVar7 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_70 = *(code **)(param_1 + 0x68);
                            pcStack_68 = *(code **)(param_1 + 0x70);
                            uVar20 = 0x152;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plStack_108 = (longlong *)0x0;
                            plStack_100 = (longlong *)0x0;
                            plStack_130 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_128 = (longlong *)0x0;
                          }
                          else {
                            iVar5 = FUN_23e97de20(plVar7,DAT_23ed6ccf0);
                            lVar10 = *plVar7;
                            *plVar7 = lVar10 + -1;
                            if (lVar10 + -1 == 0) {
                              FUN_23a334bc0();
                            }
                            if (iVar5 == -1) {
                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_70 = *(code **)(param_1 + 0x68);
                              pcStack_68 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar20 = 0x152;
                              plStack_108 = (longlong *)0x0;
                              plStack_100 = (longlong *)0x0;
                              plStack_130 = (longlong *)0x0;
                              plStack_128 = (longlong *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            }
                            else if (iVar5 == 1) {
                              plStack_128 = (longlong *)FUN_23e8bc2f0(plStack_120,_DAT_23eeadde8);
                              if (plStack_128 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcStack_70 = *(code **)(param_1 + 0x68);
                                pcStack_68 = *(code **)(param_1 + 0x70);
                                uVar20 = 0x153;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_108 = (longlong *)0x0;
                                plStack_100 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                plVar7 = (longlong *)FUN_23e8bc2f0(plStack_120,_DAT_23eeaddf0);
                                if (plVar7 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                  uVar20 = 0x154;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plStack_100 = (longlong *)0x0;
                                }
                                else {
                                  plStack_130 = (longlong *)FUN_23e8c1ce0(plVar7,_DAT_23eeaddf8);
                                  lVar10 = *plVar7;
                                  *plVar7 = lVar10 + -1;
                                  if (lVar10 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plStack_130 == (longlong *)0x0) {
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                    uVar20 = 0x154;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_108 = (longlong *)0x0;
                                    plStack_100 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar7 = (longlong *)FUN_23e8bc2f0();
                                    if (plVar7 == (longlong *)0x0) {
LAB_23e2cc0e7:
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      pcStack_70 = *(code **)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar20 = 0x155;
                                      plStack_108 = (longlong *)0x0;
                                      plStack_100 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      plVar9 = (longlong *)FUN_23e8c2690(plVar7,_DAT_23eeaddf8);
                                      *plVar7 = *plVar7 + -1;
                                      if (*plVar7 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar9 == (longlong *)0x0) {
                                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_70 = *(code **)(param_1 + 0x68);
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        uVar20 = 0x155;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        plStack_100 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_108 = (longlong *)0x0;
                                      }
                                      else {
                                        plStack_100 = (longlong *)FUN_23e8c1ce0();
                                        lVar10 = *plVar9;
                                        *plVar9 = lVar10 + -1;
                                        if (lVar10 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plStack_100 == (longlong *)0x0) goto LAB_23e2cc0e7;
                                        iVar5 = FUN_23e97de20(plStack_128,DAT_23ed6ccf0);
                                        if (iVar5 == -1) {
                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                          uVar20 = 0x157;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plStack_108 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else if (iVar5 == 1) {
                                          lVar10 = FUN_23e94f9d0(param_1,plStack_128,DAT_23ed6cd28);
                                          if (lVar10 == 0) {
LAB_23e2cc000:
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else {
                                            plVar9 = (longlong *)
                                                     FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),6
                                                                  );
                                            plVar9[3] = lVar10;
                                            plVar7 = _DAT_23eeade08;
                                            *_DAT_23eeade08 = *_DAT_23eeade08 + 1;
                                            plVar9[4] = (longlong)plVar7;
                                            lVar10 = FUN_23e94f9d0(param_1,plStack_130,DAT_23ed6cd28
                                                                  );
                                            if (lVar10 != 0) {
                                              plVar9[5] = lVar10;
                                              plVar7 = _DAT_23eeade10;
                                              *_DAT_23eeade10 = *_DAT_23eeade10 + 1;
                                              plVar9[6] = (longlong)plVar7;
                                              lVar10 = FUN_23e94f9d0(param_1,plStack_100,
                                                                     DAT_23ed6cd28);
                                              if (lVar10 != 0) {
                                                plVar9[7] = lVar10;
                                                plVar7 = _DAT_23eeade18;
                                                *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                                plVar9[8] = (longlong)plVar7;
                                                plStack_108 = (longlong *)
                                                              (*pcVar17)(DAT_23ed6cd28,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                if (plStack_108 != (longlong *)0x0)
                                                goto LAB_23e2cbae8;
                                                goto LAB_23e2cc000;
                                              }
                                            }
                                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0();
                                            }
                                          }
                                          uVar20 = 0x158;
                                          plStack_108 = (longlong *)0x0;
                                        }
                                        else {
                                          iVar5 = FUN_23e97de20(plStack_130,DAT_23ed6ccf0);
                                          if (iVar5 == -1) {
                                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar20 = 0x159;
                                            plStack_108 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else if (iVar5 == 1) {
                                            lVar10 = FUN_23e94f9d0(param_1,plStack_130,DAT_23ed6cd28
                                                                  );
                                            if (lVar10 == 0) {
LAB_23e2cbe79:
                                              pcStack_68 = *(code **)(param_1 + 0x70);
                                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pcStack_70 = *(code **)(param_1 + 0x68);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                            }
                                            else {
                                              plVar9 = (longlong *)
                                                       FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10)
                                                                     ,4);
                                              plVar9[3] = lVar10;
                                              plVar7 = _DAT_23eeade10;
                                              *_DAT_23eeade10 = *_DAT_23eeade10 + 1;
                                              plVar9[4] = (longlong)plVar7;
                                              lVar10 = FUN_23e94f9d0(param_1,plStack_100);
                                              if (lVar10 != 0) {
                                                plVar9[5] = lVar10;
                                                plVar7 = _DAT_23eeade18;
                                                *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                                plVar9[6] = (longlong)plVar7;
                                                plStack_108 = (longlong *)
                                                              (*pcVar17)(DAT_23ed6cd28,plVar9);
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                if (plStack_108 != (longlong *)0x0)
                                                goto LAB_23e2cbae8;
                                                goto LAB_23e2cbe79;
                                              }
                                              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pcStack_70 = *(code **)(param_1 + 0x68);
                                              pcStack_68 = *(code **)(param_1 + 0x70);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0();
                                                uVar20 = 0x15a;
                                                plStack_108 = (longlong *)0x0;
                                                goto LAB_23e2ca9dc;
                                              }
                                            }
                                            uVar20 = 0x15a;
                                            plStack_108 = (longlong *)0x0;
                                          }
                                          else {
                                            plStack_108 = (longlong *)
                                                          FUN_23e94f9d0(param_1,plStack_100,
                                                                        DAT_23ed6cd28);
                                            if (plStack_108 != (longlong *)0x0) {
                                              plVar9 = (longlong *)
                                                       FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10)
                                                                     ,2);
                                              plVar9[3] = (longlong)plStack_108;
                                              plVar7 = _DAT_23eeade18;
                                              *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                              plVar9[4] = (longlong)plVar7;
                                              plStack_108 = (longlong *)
                                                            (*pcVar17)(DAT_23ed6cd28,plVar9);
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plStack_108 != (longlong *)0x0) {
LAB_23e2cbae8:
                                                plVar7 = (longlong *)FUN_23e8bc2f0();
                                                if (plVar7 != (longlong *)0x0) {
                                                  *(undefined4 *)(plVar2 + 5) = 0x15e;
                                                  plVar9 = (longlong *)
                                                           FUN_23e915840(param_1,plVar7,
                                                                         _DAT_23eeada60);
                                                  *plVar7 = *plVar7 + -1;
                                                  if (*plVar7 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar9 != (longlong *)0x0) {
                                                    *plVar9 = *plVar9 + -1;
                                                    if (*plVar9 == 0) {
                                                      FUN_23a334bc0(plVar9);
                                                    }
                                                    plVar7 = (longlong *)
                                                             FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
                                                    if (plVar7 == (longlong *)0x0) {
LAB_23e2cbd3d:
                                                      auStack_78 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      pcStack_70 = *(code **)(param_1 + 0x68);
                                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar9 = (longlong *)
                                                               FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
                                                      *plVar7 = *plVar7 + -1;
                                                      if (*plVar7 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      plVar7 = _DAT_23eeadca8;
                                                      if (plVar9 == (longlong *)0x0)
                                                      goto LAB_23e2cbd3d;
                                                      plVar14 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar7 = *plVar7 + 1;
                                                      plVar14[3] = (longlong)plVar7;
                                                      lVar10 = FUN_23e8f6680();
                                                      if (lVar10 == 0) {
                                                        FUN_23e915740(param_1,auStack_78,
                                                                      DAT_23eeadd68);
LAB_23e2cbd05:
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                      }
                                                      else {
                                                        lVar10 = FUN_23e94f9d0(param_1,lVar10,
                                                                               DAT_23ed6cd28);
                                                        if (lVar10 == 0) {
                                                          pcStack_68 = *(code **)(param_1 + 0x70);
                                                          auStack_78 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          pcStack_70 = *(code **)(param_1 + 0x68);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          goto LAB_23e2cbd05;
                                                        }
                                                        plVar14[4] = lVar10;
                                                        plVar7 = _DAT_23eeadcb8;
                                                        *_DAT_23eeadcb8 = *_DAT_23eeadcb8 + 1;
                                                        plVar14[5] = (longlong)plVar7;
                                                        plVar7 = (longlong *)
                                                                 (*pcVar17)(DAT_23ed6cd28,plVar14);
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar7 != (longlong *)0x0) {
                                                          *(undefined4 *)(plVar2 + 5) = 0x15f;
                                                          plVar14 = (longlong *)
                                                                    FUN_23e914090(param_1,plVar9);
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          *plVar7 = *plVar7 + -1;
                                                          if (*plVar7 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar14 != (longlong *)0x0) {
                                                            *plVar14 = *plVar14 + -1;
                                                            if (*plVar14 == 0) {
                                                              FUN_23a334bc0(plVar14);
                                                            }
                                                            goto LAB_23e2c85c3;
                                                          }
                                                          goto LAB_23e2cbd3d;
                                                        }
                                                        auStack_78 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        pcStack_70 = *(code **)(param_1 + 0x68);
                                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar9 = *plVar9 + -1;
                                                        if (*plVar9 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                      }
                                                    }
                                                    uVar20 = 0x15f;
                                                    goto LAB_23e2ca9dc;
                                                  }
                                                }
                                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                                pcStack_70 = *(code **)(param_1 + 0x68);
                                                pcStack_68 = *(code **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                uVar20 = 0x15e;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                goto LAB_23e2ca9dc;
                                              }
                                            }
                                            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_70 = *(code **)(param_1 + 0x68);
                                            pcStack_68 = *(code **)(param_1 + 0x70);
                                            uVar20 = 0x15c;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            else {
                              plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
                              if (plVar7 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcStack_70 = *(code **)(param_1 + 0x68);
                                pcStack_68 = *(code **)(param_1 + 0x70);
                                uVar20 = 0x161;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_108 = (longlong *)0x0;
                                plStack_100 = (longlong *)0x0;
                                plStack_128 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_130 = (longlong *)0x0;
                              }
                              else {
                                *(undefined4 *)(plVar2 + 5) = 0x161;
                                plVar9 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eeada60);
                                lVar10 = *plVar7;
                                *plVar7 = lVar10 + -1;
                                if (lVar10 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar9 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pcStack_70 = *(code **)(param_1 + 0x68);
                                  pcStack_68 = *(code **)(param_1 + 0x70);
                                  uVar20 = 0x161;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_100 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plStack_128 = (longlong *)0x0;
                                }
                                else {
                                  lVar10 = *plVar9;
                                  *plVar9 = lVar10 + -1;
                                  if (lVar10 + -1 == 0) {
                                    FUN_23a334bc0(plVar9);
                                  }
                                  plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
                                  if (plVar7 == (longlong *)0x0) {
LAB_23e2cb832:
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_70 = *(code **)(param_1 + 0x68);
                                    pcStack_68 = *(code **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
                                    *plVar7 = *plVar7 + -1;
                                    if (*plVar7 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    plVar7 = _DAT_23eeadca8;
                                    if (plVar9 == (longlong *)0x0) goto LAB_23e2cb832;
                                    plVar14 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                                    *plVar7 = *plVar7 + 1;
                                    plVar14[3] = (longlong)plVar7;
                                    lVar10 = FUN_23e8f6530();
                                    if (lVar10 == 0) {
                                      FUN_23e915740(param_1,auStack_78,DAT_23eeadd28);
LAB_23e2cb7fa:
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                    else {
                                      lVar10 = FUN_23e94f9d0(param_1,lVar10,DAT_23ed6cd28);
                                      if (lVar10 == 0) {
                                        pcStack_68 = *(code **)(param_1 + 0x70);
                                        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_70 = *(code **)(param_1 + 0x68);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e2cb7fa;
                                      }
                                      plVar14[4] = lVar10;
                                      plVar7 = _DAT_23eeadcb8;
                                      *_DAT_23eeadcb8 = *_DAT_23eeadcb8 + 1;
                                      plVar14[5] = (longlong)plVar7;
                                      plVar7 = (longlong *)(*pcVar17)(DAT_23ed6cd28,plVar14);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar7 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar2 + 5) = 0x162;
                                        plVar14 = (longlong *)FUN_23e914090(param_1,plVar9);
                                        *plVar9 = *plVar9 + -1;
                                        if (*plVar9 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        *plVar7 = *plVar7 + -1;
                                        if (*plVar7 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plVar14 != (longlong *)0x0) {
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            FUN_23a334bc0(plVar14);
                                            plStack_108 = (longlong *)0x0;
                                            plStack_100 = (longlong *)0x0;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                          }
                                          else {
                                            plStack_108 = (longlong *)0x0;
                                            plStack_100 = (longlong *)0x0;
                                            plStack_130 = (longlong *)0x0;
                                            plStack_128 = (longlong *)0x0;
                                          }
                                          goto LAB_23e2c85c3;
                                        }
                                        goto LAB_23e2cb832;
                                      }
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      pcStack_70 = *(code **)(param_1 + 0x68);
                                      pcStack_68 = *(code **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar9 = *plVar9 + -1;
                                      if (*plVar9 == 0) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                  }
                                  uVar20 = 0x162;
                                  plStack_108 = (longlong *)0x0;
                                  plStack_100 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                }
                              }
                            }
                          }
                        }
                        goto LAB_23e2ca9dc;
                      }
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_70 = *(code **)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
                      iVar5 = *(int *)(lVar10 + 0xc);
                      if (*(int *)(lVar10 + 0xc) == 0) {
                        *(int *)(lVar10 + 0xc) = _DAT_23ec14e6c;
                        iVar5 = _DAT_23ec14e6c;
                        _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
                      }
                      if (_DAT_23ec14e58 != iVar5) {
                        _DAT_23ec14e58 = iVar5;
                        _DAT_23eeb02c8 =
                             FUN_23e8cbd60(lVar10,DAT_23eeaddd0,
                                           *(undefined8 *)(DAT_23eeaddd0 + 0x18));
                      }
                      if (-1 < _DAT_23eeb02c8) {
                        lVar3 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                        lVar18 = *(longlong *)(lVar3 + 8 + _DAT_23eeb02c8 * 0x10);
                        if (lVar18 != 0) goto LAB_23e2c82a2;
                        _DAT_23eeb02c8 =
                             FUN_23e8cbd60(lVar10,DAT_23eeaddd0,
                                           *(undefined8 *)(DAT_23eeaddd0 + 0x18));
                        if (-1 < _DAT_23eeb02c8) {
                          lVar18 = *(longlong *)(lVar3 + 8 + _DAT_23eeb02c8 * 0x10);
                          goto LAB_23e2cc3c2;
                        }
                      }
LAB_23e2cc3cb:
                      plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeaddd0);
                      if ((plVar9 != (longlong *)0x0) && (lVar18 = *plVar9, lVar18 != 0))
                      goto LAB_23e2c82a2;
                      FUN_23e915740(param_1,auStack_78,DAT_23eeaddd0);
                    }
                    lVar10 = *plVar7;
                    *plVar7 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                  }
LAB_23e2cc30e:
                  uVar20 = 0x14f;
                  plStack_108 = (longlong *)0x0;
                  plStack_100 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  plStack_118 = (longlong *)0x0;
                }
              }
            }
          }
        }
      }
LAB_23e2ca9dc:
      pcVar16 = pcStack_68;
      pcStack_68 = (code *)0x0;
      pcStack_88 = pcVar16;
      plVar7 = *(longlong **)(param_1 + 0x138);
      plStack_98 = (longlong *)auStack_78;
      pcStack_90 = pcStack_70;
      auStack_78 = (undefined1  [8])0x0;
      pcStack_70 = (code *)0x0;
      if (plVar7 != (longlong *)0x0) {
        *plVar7 = *plVar7 + 1;
      }
      if (pcVar16 == (code *)0x0) {
        lVar10 = FUN_23e8d6280(plVar2,uVar20);
      }
      else {
        lVar10 = FUN_23e8d6280(plVar2,uVar20);
        *(code **)(lVar10 + 0x10) = pcVar16;
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      }
      if ((pcStack_88 != (code *)0x0) &&
         (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1, *(longlong *)pcStack_88 == 0)) {
        FUN_23a334bc0();
      }
      pcStack_88 = (code *)lVar10;
      FUN_23a35ef40(param_1,pplStack_e8);
      iVar5 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      if (iVar5 == 0) {
        cVar4 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_78);
        iVar5 = 0;
        if (cVar4 == '\0') {
          iVar5 = 0x13f;
        }
        pcVar16 = pcStack_68;
        auVar19 = auStack_78;
        pcVar17 = pcStack_70;
        if ((pcStack_68 != (code *)0x0) && (*(longlong **)(pcStack_68 + 0x18) == plVar2)) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcStack_68 + 0x24);
        }
      }
      else {
        plVar9 = *(longlong **)(param_1 + 0x138);
        *plVar9 = *plVar9 + 1;
        lVar10 = FUN_23e8f6a70();
        if (lVar10 == 0) {
          FUN_23e915740(param_1,auStack_78,DAT_23eeadcf8);
LAB_23e2cae03:
          iVar5 = 0x165;
        }
        else {
          plVar11 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eeade28);
          plVar14 = _DAT_23eeade30;
          if (plVar11 == (longlong *)0x0) {
LAB_23e2caea1:
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2cae03;
          }
          plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
          *plVar14 = *plVar14 + 1;
          plVar12[3] = (longlong)plVar14;
          lVar10 = FUN_23e94f9d0(param_1,plVar9,DAT_23ed6cd28);
          if (lVar10 == 0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              FUN_23a334bc0(plVar12);
            }
            goto LAB_23e2cae03;
          }
          plVar12[4] = lVar10;
          plVar14 = (longlong *)(*pcVar17)(DAT_23ed6cd28,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            FUN_23a334bc0(plVar12);
          }
          if (plVar14 == (longlong *)0x0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            goto LAB_23e2cae03;
          }
          *(undefined4 *)(plVar2 + 5) = 0x165;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0(plVar11);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            FUN_23a334bc0(plVar14);
          }
          if (plVar12 == (longlong *)0x0) goto LAB_23e2caea1;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            FUN_23a334bc0(plVar12);
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb88);
          if (plVar14 == (longlong *)0x0) {
LAB_23e2caf1b:
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            iVar5 = 0x166;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0x166;
            plVar11 = (longlong *)FUN_23e915840(param_1,plVar14,_DAT_23eeada60,plVar6);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              FUN_23a334bc0(plVar14);
            }
            if (plVar11 == (longlong *)0x0) goto LAB_23e2caf1b;
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            plVar14 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
            if (plVar14 != (longlong *)0x0) {
              *(undefined4 *)(plVar2 + 5) = 0x167;
              plVar11 = (longlong *)FUN_23e915840(param_1,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                FUN_23a334bc0(plVar14);
              }
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  FUN_23a334bc0(plVar9);
                }
                FUN_23ebf6ae0(param_1,plVar7);
                goto LAB_23e2c85c3;
              }
            }
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_70 = *(code **)(param_1 + 0x68);
            pcStack_68 = *(code **)(param_1 + 0x70);
            iVar5 = 0x167;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
        }
        pcVar16 = pcStack_68;
        pcVar17 = pcStack_70;
        auVar19 = auStack_78;
        _auStack_78 = (undefined1  [16])0x0;
        pcStack_68 = (code *)0x0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          FUN_23a334bc0(plVar9);
        }
      }
      pcStack_70 = pcVar17;
      auStack_78 = auVar19;
      pcVar17 = pcStack_70;
      auVar19 = auStack_78;
      pcStack_68 = (code *)0x0;
      _auStack_78 = (undefined1  [16])0x0;
      FUN_23ebf6ae0(param_1,plVar7);
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      pcStack_68 = pcVar16;
      auStack_78 = auVar19;
      pcStack_70 = pcVar17;
      goto LAB_23e2c6ef9;
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb88);
    lVar10 = _DAT_23eeadd38;
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x169;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_110 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x169;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eeada60,*(undefined8 *)(lVar10 + 0x18))
    ;
    lVar10 = *plVar7;
    *plVar7 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x169;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    lVar10 = *plVar9;
    *plVar9 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadb98);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x16a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_110 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    *(undefined4 *)(plVar2 + 5) = 0x16a;
    plVar9 = (longlong *)FUN_23e915840();
    lVar10 = *plVar7;
    *plVar7 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x16a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      pplStack_e8 = (longlong **)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_100 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_138 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    lVar10 = *plVar9;
    *plVar9 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0(plVar9);
    }
    plStack_108 = (longlong *)0x0;
    plStack_100 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
LAB_23e2c85c3:
    plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eead900);
    if (plVar7 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x16d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pplStack_e8 = (longlong **)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_f8 = (longlong *)0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    pplStack_e8 = (longlong **)FUN_23e8bc2f0(plVar7,_DAT_23eeadd18);
    lVar10 = *plVar7;
    *plVar7 = lVar10 + -1;
    if (lVar10 + -1 == 0) {
      FUN_23a334bc0();
    }
    if (pplStack_e8 == (longlong **)0x0) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x16d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    iVar5 = FUN_23a35f020();
    if (iVar5 == -1) {
LAB_23e2cb68f:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      iVar5 = 0x16e;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_f8 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcStack_70 = *(code **)(param_1 + 0x68);
      goto LAB_23e2c6ef9;
    }
    if (iVar5 != 0) {
      plVar7 = (longlong *)FUN_23e8bd600(param_1,pplStack_e8);
      if (plVar7 != (longlong *)0x0) {
        cVar4 = FUN_23e8d1960(plVar7,8);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          FUN_23a334bc0(plVar7);
        }
        if (cVar4 == '\0') goto LAB_23e2c8650;
        plVar7 = (longlong *)FUN_23a38cc10(param_1,pplStack_e8,_DAT_23eeade38);
        if (plVar7 == (longlong *)0x0) {
LAB_23e2cb351:
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          lVar10 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0();
          }
          if (lVar10 == 0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_68 = *(code **)(param_1 + 0x70);
            iVar5 = 0x16f;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plStack_f8 = (longlong *)0x0;
            pcStack_70 = *(code **)(param_1 + 0x68);
            goto LAB_23e2c6ef9;
          }
          plVar9 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
          uVar20 = _DAT_23eeade48;
          plVar9[3] = lVar10;
          plVar7 = _DAT_23eeade40;
          *_DAT_23eeade40 = *_DAT_23eeade40 + 1;
          plVar9[4] = (longlong)plVar7;
          plVar7 = (longlong *)FUN_23a38cc10(param_1,pplStack_e8,uVar20);
          if (plVar7 != (longlong *)0x0) {
            lVar10 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              FUN_23a334bc0();
            }
            if (lVar10 != 0) {
              plVar9[5] = lVar10;
              plStack_f8 = (longlong *)(*pcVar17)(DAT_23ed6cd28,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                FUN_23a334bc0();
              }
              if (plStack_f8 == (longlong *)0x0) goto LAB_23e2cb351;
              plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadba8);
              if (plVar7 != (longlong *)0x0) {
                *(undefined4 *)(plVar2 + 5) = 0x170;
                plVar9 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eeada60,plStack_f8);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar9 != (longlong *)0x0) {
                  *plVar9 = *plVar9 + -1;
                  pcVar17 = _Py_NoneStruct_exref;
                  if (*plVar9 == 0) {
                    FUN_23a334bc0(plVar9);
                    pcVar17 = _Py_NoneStruct_exref;
                  }
                  goto LAB_23e2c730b;
                }
              }
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcStack_68 = *(code **)(param_1 + 0x70);
              iVar5 = 0x170;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcStack_70 = *(code **)(param_1 + 0x68);
              goto LAB_23e2c6ef9;
            }
          }
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_70 = *(code **)(param_1 + 0x68);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            FUN_23a334bc0();
          }
        }
        iVar5 = 0x16f;
        plStack_f8 = (longlong *)0x0;
        goto LAB_23e2c6ef9;
      }
      goto LAB_23e2cb68f;
    }
LAB_23e2c8650:
    plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeadba8);
    if (plVar7 == (longlong *)0x0) {
LAB_23e2cb0b4:
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2cb09e:
      iVar5 = 0x172;
      plStack_f8 = (longlong *)0x0;
      goto LAB_23e2c6ef9;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eeada60);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0();
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e2cb0b4;
    iVar5 = FUN_23a35f020();
    if (iVar5 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_70 = *(code **)(param_1 + 0x68);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        FUN_23a334bc0();
      }
      goto LAB_23e2cb09e;
    }
    *(undefined4 *)(plVar2 + 5) = 0x172;
    plVar7 = (longlong *)FUN_23e914090();
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      FUN_23a334bc0();
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23e2cb0b4;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      FUN_23a334bc0(plVar7);
      plStack_f8 = (longlong *)0x0;
      pcVar17 = _Py_NoneStruct_exref;
    }
    else {
      plStack_f8 = (longlong *)0x0;
      pcVar17 = _Py_NoneStruct_exref;
    }
LAB_23e2c730b:
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar2 = *(longlong **)(lVar10 + 0x28);
    plVar7 = (longlong *)plVar2[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
    *(undefined4 *)(plVar2 + 8) = 0xffffffff;
    if (plVar7 != (longlong *)0x0) {
      plVar2[2] = 0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))();
      }
    }
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    plVar2[0xf] = 0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if ((plStack_138 != (longlong *)0x0) &&
       (lVar10 = *plStack_138, *plStack_138 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_138[1] + 0x30))(plStack_138);
    }
    if ((plStack_110 != (longlong *)0x0) &&
       (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_110[1] + 0x30))(plStack_110);
    }
    if ((plStack_f0 != (longlong *)0x0) &&
       (lVar10 = *plStack_f0, *plStack_f0 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
    }
    if ((plStack_118 != (longlong *)0x0) &&
       (lVar10 = *plStack_118, *plStack_118 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
    if ((plStack_120 != (longlong *)0x0) &&
       (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_120[1] + 0x30))(plStack_120);
    }
    if ((plStack_128 != (longlong *)0x0) &&
       (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_128[1] + 0x30))(plStack_128);
    }
    if ((plStack_130 != (longlong *)0x0) &&
       (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
    if ((plStack_100 != (longlong *)0x0) &&
       (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_100[1] + 0x30))(plStack_100);
    }
    if ((plStack_108 != (longlong *)0x0) &&
       (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
    if ((pplStack_e8 != (longlong **)0x0) &&
       (lVar10 = (longlong)*pplStack_e8, *pplStack_e8 = (longlong *)(lVar10 + -1), lVar10 + -1 == 0)
       ) {
      (**(code **)((longlong)pplStack_e8[1] + 0x30))(pplStack_e8);
    }
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar10 = *plStack_f8, *plStack_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
LAB_23e2c6dfb:
  lVar10 = *param_3;
  *param_3 = lVar10 + -1;
  if (lVar10 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  return pcVar17;
}
