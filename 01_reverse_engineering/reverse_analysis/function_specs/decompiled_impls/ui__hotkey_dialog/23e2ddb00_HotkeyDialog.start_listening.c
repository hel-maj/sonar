/* ===== 23e2ddb00 ui.hotkey_dialog:117 ===== */
/* ghidra_name=FUN_23e2ddb00 entry=23e2ddb00 size=3567 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2ddb00(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong *plVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  undefined4 uVar20;
  code *pcStack_a0;
  code *pcStack_98;
  code *pcStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [16];
  code *apcStack_68 [5];
  
  plVar10 = _DAT_23eeb0210;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb0210 == (longlong *)0x0) {
LAB_23e2ddb49:
    _DAT_23eeb0210 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0208,DAT_23eeb0268,0x18);
  }
  else {
    lVar14 = *_DAT_23eeb0210;
    if (1 < lVar14) {
      *_DAT_23eeb0210 = lVar14 + -1;
      goto LAB_23e2ddb49;
    }
    if (_DAT_23eeb0210[2] != 0) {
      *_DAT_23eeb0210 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2ddb49;
    }
  }
  plVar3 = _DAT_23eeb0210;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb0210 + 9;
  lVar12 = *(longlong *)(lVar14 + 8);
  _DAT_23eeb0210[0xf] = lVar12;
  *(longlong **)(lVar14 + 8) = plVar10;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar13 = DAT_23eead3f0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar10 == (longlong *)0x0) {
LAB_23e2ddd20:
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    pcVar19 = *(code **)(param_1 + 0x70);
    uVar20 = 0x79;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x79;
    plVar11 = (longlong *)FUN_23e915840(param_1,plVar10,_DAT_23eead5e0,plVar2);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e2ddd20;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    *(undefined4 *)(plVar3 + 5) = 0x7c;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar1,_DAT_23eead5e8);
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      pcVar19 = _Py_NoneStruct_exref;
      if (*plVar10 == 0) {
LAB_23e2de302:
        (**(code **)(plVar10[1] + 0x30))();
      }
LAB_23e2ddc61:
      lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar10 = *(longlong **)(lVar14 + 0x28);
      plVar3 = (longlong *)plVar10[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
      *(undefined4 *)(plVar10 + 8) = 0xffffffff;
      if (plVar3 != (longlong *)0x0) {
        plVar10[2] = 0;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      plVar10[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return pcVar19;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return pcVar19;
    }
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    pcVar19 = *(code **)(param_1 + 0x70);
    uVar20 = 0x7c;
  }
  plVar11 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (plVar11 != (longlong *)0x0) {
    *plVar11 = *plVar11 + 1;
  }
  pcVar17 = DAT_23ed6a4f8;
  apcStack_68[0] = pcVar19;
  if (pcVar19 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcStack_a0 = _PyRuntime_exref;
    *(longlong *)(pcVar17 + 0x10) = 0;
    *(longlong **)(pcVar17 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcStack_a0 + 0x1f8);
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(pcVar17 + 0x24) = uVar20;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar12 = *(longlong *)(pcVar17 + -8);
    puVar4 = *(undefined8 **)(lVar14 + 8);
    *puVar4 = pcVar17 + -0x10;
    *(longlong *)(pcVar17 + -0x10) = lVar14;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
    *(code **)(lVar14 + 8) = pcVar17 + -0x10;
    if ((apcStack_68[0] != (code *)0x0) &&
       (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
       *(longlong *)apcStack_68[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))(apcStack_68[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcStack_a0 = _PyRuntime_exref;
    *(longlong **)(pcVar17 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcStack_a0 + 0x1f8);
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(pcVar17 + 0x24) = uVar20;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar12 = *(longlong *)(pcVar17 + -8);
    puVar4 = *(undefined8 **)(lVar14 + 8);
    *puVar4 = pcVar17 + -0x10;
    *(longlong *)(pcVar17 + -0x10) = lVar14;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
    *(code **)(lVar14 + 8) = pcVar17 + -0x10;
    *(code **)(pcVar17 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    if ((apcStack_68[0] != (code *)0x0) &&
       (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
       *(longlong *)apcStack_68[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))();
    }
  }
  pcVar19 = _Py_NoneStruct_exref;
  apcStack_68[0] = pcVar17;
  if (((code *)auStack_78._0_8_ != (code *)0x0) &&
     ((code *)auStack_78._0_8_ != _Py_NoneStruct_exref)) {
    FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,apcStack_68);
  }
  plVar10 = *(longlong **)(auStack_78._8_8_ + 0x28);
  if (apcStack_68[0] == pcVar19) {
    pcVar17 = (code *)0x0;
  }
  else {
    pcVar17 = apcStack_68[0];
    if (apcStack_68[0] != (code *)0x0) {
      *(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + 1;
    }
  }
  *(code **)(auStack_78._8_8_ + 0x28) = pcVar17;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  plVar10 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_78._8_8_;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))();
  }
  *(longlong *)auStack_78._0_8_ = *(longlong *)auStack_78._0_8_ + -1;
  if (*(longlong *)auStack_78._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_78._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_68[0] != (code *)0x0) &&
     (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
     *(longlong *)apcStack_68[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))();
  }
  pcVar18 = *(code **)(param_1 + 0x138);
  apcStack_68[0] = (code *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  pcVar17 = *(code **)PyExc_Exception_exref;
  pcVar16 = *(code **)(pcVar18 + 8);
  if ((*(uint *)(*(longlong *)(pcVar17 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar17 + 8) + 0xa8) < 0) &&
       (((byte)pcVar17[0xab] & 0x40) != 0)) {
      pcVar5 = *(code **)(pcVar16 + 8);
      if ((*(uint *)(pcVar5 + 0xa8) & 0x40000000) == 0) {
        if (((int)*(uint *)(pcVar5 + 0xa8) < 0) && (((byte)pcVar16[0xab] & 0x40) != 0))
        goto LAB_23e2de351;
      }
      else {
        pcVar16 = pcVar5;
        if (*(int *)(*(longlong *)(pcVar5 + 8) + 0xa8) < 0) goto LAB_23e2de351;
      }
      if (pcVar16 != pcVar17) goto LAB_23e2ddf82;
    }
    else {
      plVar15 = *(longlong **)PyExc_TypeError_exref;
      uVar13 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar6 = *(longlong **)(param_1 + 0x60);
      plVar7 = *(longlong **)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar15;
      *plVar15 = *plVar15 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar13;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))();
      }
      if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
LAB_23e2de3f8:
      if ((plVar10 == (longlong *)0x0) || (*plVar10 = *plVar10 + -1, *plVar10 != 0)) {
LAB_23e2de17a:
        pcVar18 = *(code **)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        pcVar18 = *(code **)(param_1 + 0x138);
      }
    }
LAB_23e2de181:
    do {
      pcVar17 = (code *)&DAT_23ed6cce0;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
      uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
      pcVar16 = _DAT_23eead5f0;
      lVar14 = *(longlong *)(param_1 + 0x10);
      plVar10 = *(longlong **)(lVar14 + 0xe20);
      if (plVar10 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar12 = plVar10[3];
        *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
        *(longlong *)(lVar14 + 0xe20) = lVar12;
        *plVar10 = 1;
      }
      plVar10[4] = 0;
      lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_a0 + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = plVar10[-1];
      puVar4 = *(undefined8 **)(lVar14 + 8);
      *puVar4 = plVar10 + -2;
      plVar10[-2] = lVar14;
      plVar10[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar14 + 8) = plVar10 + -2;
      plVar15 = DAT_23ed6a4c0;
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      plVar10[3] = (longlong)pcVar16;
      uVar8 = DAT_23ed6cd28;
      if (plVar15 != (longlong *)0x0) {
LAB_23e2de241:
        uStack_80 = uVar8;
        pcStack_88 = pcVar18;
        lVar14 = FUN_23e94ed00(param_1,plVar15,&pcStack_88);
        if (lVar14 == 0) {
          pcStack_98 = *(code **)(param_1 + 0x68);
          plVar15 = *(longlong **)(param_1 + 0x60);
          pcVar19 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
        }
        else {
          plVar10[4] = lVar14;
          plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar15 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x7f;
            plVar10 = (longlong *)FUN_23e914090(param_1,uVar13,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (plVar10 != (longlong *)0x0) {
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
              if (*(longlong *)pcVar18 == 0) {
                (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
              }
              plVar10 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar11;
              if ((plVar10 == (longlong *)0x0) || (*plVar10 = *plVar10 + -1, *plVar10 != 0))
              goto LAB_23e2ddc61;
              goto LAB_23e2de302;
            }
          }
          pcStack_98 = *(code **)(param_1 + 0x68);
          plVar15 = *(longlong **)(param_1 + 0x60);
          pcVar19 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
        if (*(longlong *)pcVar18 == 0) {
          (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
        }
        plVar10 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar11;
        if (plVar10 == (longlong *)0x0) {
          if (pcVar19 == (code *)0x0) {
LAB_23e2de7b0:
            iVar9 = 0x7f;
            goto LAB_23e2de7c0;
          }
          plVar10 = *(longlong **)(pcVar19 + 0x18);
        }
        else {
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
            if (pcVar19 != (code *)0x0) {
              iVar9 = 0x7f;
              goto LAB_23e2de645;
            }
            iVar9 = 0x7f;
            goto LAB_23e2de7c0;
          }
          if (pcVar19 == (code *)0x0) goto LAB_23e2de7b0;
          plVar10 = *(longlong **)(pcVar19 + 0x18);
        }
        pcVar17 = pcVar19;
        if (plVar3 == plVar10) goto LAB_23e2de080;
        uVar20 = 0x7f;
        goto LAB_23e2ddfe9;
      }
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
        DAT_23ed6a4c0 = plVar15;
        goto LAB_23e2de241;
      }
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e2de351:
      lVar14 = *(longlong *)(pcVar16 + 0x158);
      if (lVar14 != 0) {
        if (*(longlong *)(lVar14 + 0x10) < 1) break;
        lVar12 = 0;
        while (pcVar17 != *(code **)(lVar14 + 0x18 + lVar12 * 8)) {
          lVar12 = lVar12 + 1;
          if (*(longlong *)(lVar14 + 0x10) == lVar12) goto LAB_23e2ddf82;
        }
        goto LAB_23e2de181;
      }
      do {
        if (pcVar17 == pcVar16) goto LAB_23e2de181;
        pcVar16 = *(code **)(pcVar16 + 0x100);
      } while (pcVar16 != (code *)0x0);
    } while (pcVar17 == PyBaseObject_Type_exref);
  }
  else {
    lVar14 = *(longlong *)(pcVar17 + 0x10);
    if (0 < lVar14) {
      lVar12 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar17 + lVar12 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar17 + lVar12 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar15 = *(longlong **)PyExc_TypeError_exref;
          uVar13 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar6 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x68);
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar15;
          *plVar15 = *plVar15 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar13;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))();
          }
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          goto LAB_23e2de3f8;
        }
        lVar12 = lVar12 + 1;
      } while (lVar14 != lVar12);
      lVar12 = 0;
      do {
        iVar9 = FUN_23a35ebd0(param_1,pcVar16,*(undefined8 *)(pcVar17 + lVar12 * 8 + 0x18));
        if (iVar9 != 0) goto LAB_23e2de17a;
        lVar12 = lVar12 + 1;
      } while (lVar14 != lVar12);
      pcVar18 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23e2ddf82:
  if ((pcVar18 == (code *)0x0) || (pcVar18 == pcVar19)) {
    plVar15 = *(longlong **)PyExc_RuntimeError_exref;
    pcStack_98 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar18 = *(code **)(param_1 + 0x138);
    *plVar15 = *plVar15 + 1;
    *(longlong **)(param_1 + 0x138) = plVar11;
    if (pcVar18 != (code *)0x0) {
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
      iVar9 = 0x77;
      if (*(longlong *)pcVar18 == 0) goto LAB_23e2de8d3;
    }
    iVar9 = 0x77;
  }
  else {
    plVar15 = *(longlong **)(pcVar18 + 8);
    pcVar19 = *(code **)(pcVar18 + 0x28);
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    *plVar15 = *plVar15 + 1;
    pcStack_98 = pcVar18;
    if (pcVar19 != (code *)0x0) {
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      if (plVar3 == *(longlong **)(pcVar19 + 0x18)) {
        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar19 + 0x24);
      }
      *(longlong **)(param_1 + 0x138) = plVar11;
      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
      if (*(longlong *)pcVar18 == 0) {
        (*(code *)plVar15[6])(pcVar18);
        iVar9 = 0;
LAB_23e2de645:
        pcVar17 = pcVar19;
        if (plVar3 == *(longlong **)(pcVar19 + 0x18)) goto LAB_23e2de080;
        uVar20 = 0x7f;
        if (iVar9 == 0) goto LAB_23e2ddfe5;
      }
      else {
        pcVar17 = pcVar19;
        if (*(longlong **)(pcVar19 + 0x18) == plVar3) goto LAB_23e2de080;
LAB_23e2ddfe5:
        uVar20 = (undefined4)plVar3[5];
      }
LAB_23e2ddfe9:
      pcVar17 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar17 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar14 = *(longlong *)(pcStack_a0 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      *(undefined4 *)(pcVar17 + 0x24) = uVar20;
      lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      lVar12 = *(longlong *)(pcVar17 + -8);
      puVar4 = *(undefined8 **)(lVar14 + 8);
      *puVar4 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar14;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
      lVar12 = *(longlong *)pcVar19;
      *(code **)(lVar14 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar19;
      if (lVar12 == 0) {
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
      }
      goto LAB_23e2de080;
    }
    *(longlong **)(param_1 + 0x138) = plVar11;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
    if (*(longlong *)pcVar18 == 0) {
      iVar9 = 0;
LAB_23e2de8d3:
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
      if (iVar9 != 0) goto LAB_23e2de7c0;
    }
    iVar9 = (int)plVar3[5];
  }
LAB_23e2de7c0:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar19 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar19;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar17 + 0x10) = 0;
  *(longlong **)(pcVar17 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar14 = *(longlong *)(pcStack_a0 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar14 = *(longlong *)(lVar14 + 0x10);
  *(int *)(pcVar17 + 0x24) = iVar9;
  lVar14 = *(longlong *)(lVar14 + 0x2e8);
  lVar12 = *(longlong *)(pcVar17 + -8);
  puVar4 = *(undefined8 **)(lVar14 + 8);
  *puVar4 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar14;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
  *(code **)(lVar14 + 8) = pcVar17 + -0x10;
LAB_23e2de080:
  FUN_23e8bba40(plVar3,&DAT_23ec5b355,plVar1,plVar2,0);
  if (_DAT_23eeb0210 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb0210 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar14 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  plVar3 = (longlong *)plVar10[2];
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar15,pcStack_98,pcVar17);
  return (code *)0x0;
}
