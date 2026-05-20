/* ===== 23e12ca30 telegram.notification_manager:23 ===== */
/* ghidra_name=FUN_23e12ca30 entry=23e12ca30 size=3920 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e12ca30(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined8 uVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  int iVar21;
  longlong *plStack_b0;
  code *pcStack_a8;
  undefined1 auStack_88 [16];
  code *apcStack_78 [2];
  longlong *plStack_68;
  code *pcStack_60;
  code *pcStack_58;
  
  plVar11 = _DAT_23eeaadf0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eeaadf0 == (longlong *)0x0) {
LAB_23e12ca75:
    _DAT_23eeaadf0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaade8,DAT_23eeaae08,0x18);
  }
  else {
    lVar10 = *_DAT_23eeaadf0;
    if (1 < lVar10) {
      *_DAT_23eeaadf0 = lVar10 + -1;
      goto LAB_23e12ca75;
    }
    if (_DAT_23eeaadf0[2] != 0) {
      *_DAT_23eeaadf0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e12ca75;
    }
  }
  plVar5 = _DAT_23eeaadf0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeaadf0 + 9;
  lVar12 = *(longlong *)(lVar10 + 8);
  _DAT_23eeaadf0[0xf] = lVar12;
  *(longlong **)(lVar10 + 8) = plVar11;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar13 = DAT_23eea8130;
  *(undefined4 *)(plVar5 + 8) = 0;
  cVar8 = FUN_23e8d9ac0(plVar1,uVar13,plVar2);
  if (cVar8 == '\0') {
    plStack_b0 = *(longlong **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar18 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar20 == (code *)0x0) {
      iVar9 = 0x19;
      pcStack_a8 = _PyRuntime_exref;
      goto LAB_23e12d5a9;
    }
    pcVar17 = pcVar20;
    pcVar19 = pcVar18;
    if (*(longlong **)(pcVar20 + 0x18) == plVar5) goto LAB_23e12ce73;
    pcStack_a8 = _PyRuntime_exref;
    iVar9 = 0x19;
LAB_23e12cfcd:
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
    *(longlong **)(pcVar17 + 0x18) = plVar5;
    *plVar5 = *plVar5 + 1;
    lVar10 = *(longlong *)(pcStack_a8 + 0x1f8);
    *(int *)(pcVar17 + 0x24) = iVar9;
    *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar12 = *(longlong *)(pcVar17 + -8);
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = pcVar17 + -0x10;
    *(longlong *)(pcVar17 + -0x10) = lVar10;
    *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
    lVar12 = *(longlong *)pcVar20;
    *(code **)(lVar10 + 8) = pcVar17 + -0x10;
    *(code **)(pcVar17 + 0x10) = pcVar20;
    pcVar19 = pcVar18;
    if (lVar12 == 0) {
      (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
    }
    goto LAB_23e12ce73;
  }
  cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eea8138,plVar3);
  if (cVar8 == '\0') {
    plStack_b0 = *(longlong **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar18 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar20 != (code *)0x0) {
      pcVar17 = pcVar20;
      pcVar19 = pcVar18;
      if (plVar5 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23e12ce73;
      iVar9 = 0x1a;
      pcStack_a8 = _PyRuntime_exref;
      goto LAB_23e12cfcd;
    }
    pcStack_a8 = _PyRuntime_exref;
    iVar9 = 0x1a;
  }
  else {
    lVar10 = FUN_23e8ff8f0();
    if (lVar10 == 0) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eea8148);
      pcVar20 = pcStack_58;
      auStack_88._0_8_ = plStack_68;
      auStack_88._8_8_ = pcStack_60;
    }
    else {
      *(undefined4 *)(plVar5 + 5) = 0x1d;
      plVar11 = (longlong *)FUN_23e91bfe0(param_1,lVar10,_DAT_23eea8150);
      if (plVar11 != (longlong *)0x0) {
        cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eea8140,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        pcVar20 = _Py_NoneStruct_exref;
        if (cVar8 != '\0') goto LAB_23e12d250;
      }
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      auStack_88._8_8_ = *(code **)(param_1 + 0x68);
    }
    plVar11 = *(longlong **)(param_1 + 0x138);
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    apcStack_78[0] = pcVar20;
    if (pcVar20 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar20 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar20;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x1dffffffff;
      pcStack_a8 = _PyRuntime_exref;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = *(longlong *)(pcVar18 + -8);
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar10;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
      *(code **)(lVar10 + 8) = pcVar18 + -0x10;
      if ((apcStack_78[0] != (code *)0x0) &&
         (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
         *(longlong *)apcStack_78[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))(apcStack_78[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x1dffffffff;
      pcStack_a8 = _PyRuntime_exref;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = *(longlong *)(pcVar18 + -8);
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar10;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
      *(code **)(lVar10 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar20;
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
      if ((apcStack_78[0] != (code *)0x0) &&
         (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
         *(longlong *)apcStack_78[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))();
      }
    }
    pcVar20 = _Py_NoneStruct_exref;
    apcStack_78[0] = pcVar18;
    if (((code *)auStack_88._0_8_ != (code *)0x0) &&
       ((code *)auStack_88._0_8_ != _Py_NoneStruct_exref)) {
      FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,apcStack_78);
    }
    plVar14 = *(longlong **)(auStack_88._8_8_ + 0x28);
    if (apcStack_78[0] == pcVar20) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = apcStack_78[0];
      if (apcStack_78[0] != (code *)0x0) {
        *(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + 1;
      }
    }
    *(code **)(auStack_88._8_8_ + 0x28) = pcVar18;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    plVar14 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_88._8_8_;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    *(longlong *)auStack_88._0_8_ = *(longlong *)auStack_88._0_8_ + -1;
    if (*(longlong *)auStack_88._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_88._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_78[0] != (code *)0x0) &&
       (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
       *(longlong *)apcStack_78[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))();
    }
    pcVar19 = *(code **)(param_1 + 0x138);
    apcStack_78[0] = (code *)0x0;
    auStack_88 = (undefined1  [16])0x0;
    pcVar18 = *(code **)PyExc_RuntimeError_exref;
    pcVar17 = *(code **)(pcVar19 + 8);
    if ((*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) & 0x4000000) == 0) {
      if (((int)*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) < 0) &&
         (((byte)pcVar18[0xab] & 0x40) != 0)) {
        pcVar7 = *(code **)(pcVar17 + 8);
        if ((*(uint *)(pcVar7 + 0xa8) & 0x40000000) == 0) {
          if ((-1 < (int)*(uint *)(pcVar7 + 0xa8)) || (((byte)pcVar17[0xab] & 0x40) == 0))
          goto LAB_23e12d692;
        }
        else {
          pcVar17 = pcVar7;
          if (-1 < *(int *)(*(longlong *)(pcVar7 + 8) + 0xa8)) {
LAB_23e12d692:
            if (pcVar18 != pcVar17) goto LAB_23e12ce07;
            goto LAB_23e12d0fb;
          }
        }
        lVar10 = *(longlong *)(pcVar17 + 0x158);
        if (lVar10 == 0) {
          do {
            if (pcVar18 == pcVar17) goto LAB_23e12d0fb;
            pcVar17 = *(code **)(pcVar17 + 0x100);
          } while (pcVar17 != (code *)0x0);
          if (pcVar18 == PyBaseObject_Type_exref) goto LAB_23e12d0fb;
        }
        else {
          if (*(longlong *)(lVar10 + 0x10) < 1) goto LAB_23e12ce07;
          lVar12 = 0;
          do {
            if (pcVar18 == *(code **)(lVar10 + 0x18 + lVar12 * 8)) goto LAB_23e12d0fb;
            lVar12 = lVar12 + 1;
          } while (*(longlong *)(lVar10 + 0x10) != lVar12);
        }
LAB_23e12ce00:
        pcVar19 = *(code **)(param_1 + 0x138);
        goto LAB_23e12ce07;
      }
LAB_23e12d070:
      plVar14 = *(longlong **)PyExc_TypeError_exref;
      uVar13 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar15 = *(longlong **)(param_1 + 0x60);
      plVar16 = *(longlong **)(param_1 + 0x70);
      plVar6 = *(longlong **)(param_1 + 0x68);
      *(longlong **)(param_1 + 0x60) = plVar14;
      *plVar14 = *plVar14 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar13;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))();
      }
      if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
LAB_23e12d0fb:
      lVar10 = FUN_23e8ff8f0();
      if (lVar10 != 0) {
        *(undefined4 *)(plVar5 + 5) = 0x1f;
        plVar14 = (longlong *)FUN_23e91bfe0(param_1,lVar10,_DAT_23eea8158);
        if (plVar14 != (longlong *)0x0) {
          cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eea8140,plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (cVar8 == '\0') {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            pcStack_58 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_60 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e12d501;
          }
          lVar10 = FUN_23e8ff8f0();
          if (lVar10 == 0) {
            FUN_23e915740(param_1,&plStack_68,_DAT_23eea8148);
            plStack_b0 = plStack_68;
            goto LAB_23e12d914;
          }
          plVar14 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eea8160);
          if (plVar14 == (longlong *)0x0) {
            plStack_b0 = *(longlong **)(param_1 + 0x60);
            plVar14 = *(longlong **)(param_1 + 0x138);
            pcVar18 = *(code **)(param_1 + 0x68);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(longlong **)(param_1 + 0x138) = plVar11;
            if (plVar14 != (longlong *)0x0) goto LAB_23e12d8c5;
            iVar9 = 0x20;
            if (pcVar20 != (code *)0x0) goto LAB_23e12d57a;
          }
          else {
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
            if (plVar15 == (longlong *)0x0) {
              plStack_b0 = *(longlong **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar14 = *plVar14 + -1;
              pcStack_58 = pcVar20;
              pcStack_60 = pcVar18;
              if (*plVar14 != 0) goto LAB_23e12d914;
              (**(code **)(plVar14[1] + 0x30))(plVar14);
              plVar14 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar11;
            }
            else {
              *(undefined4 *)(plVar5 + 5) = 0x20;
              plVar16 = (longlong *)FUN_23e914090(param_1,plVar14,plVar15);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar5 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar11;
                if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                  (**(code **)(plVar5[1] + 0x30))();
                }
LAB_23e12d250:
                lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar11 = *(longlong **)(lVar10 + 0x28);
                plVar5 = (longlong *)plVar11[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
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
                *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                plVar11[0xf] = 0;
                *plVar1 = *plVar1 + -1;
                if (*plVar1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 != 0) {
                  return pcVar20;
                }
                (**(code **)(plVar3[1] + 0x30))(plVar3);
                return pcVar20;
              }
              plStack_b0 = *(longlong **)(param_1 + 0x60);
              pcStack_58 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcStack_60 = *(code **)(param_1 + 0x68);
LAB_23e12d914:
              plVar14 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar11;
              pcVar18 = pcStack_60;
              pcVar20 = pcStack_58;
            }
            if (plVar14 != (longlong *)0x0) {
LAB_23e12d8c5:
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                iVar9 = 0x20;
                goto LAB_23e12d525;
              }
            }
            if (pcVar20 != (code *)0x0) {
              iVar9 = 0x20;
              goto LAB_23e12d57a;
            }
          }
          iVar9 = 0x20;
          goto LAB_23e12d5a9;
        }
        plStack_b0 = *(longlong **)(param_1 + 0x60);
        plVar14 = *(longlong **)(param_1 + 0x138);
        pcVar18 = *(code **)(param_1 + 0x68);
        pcVar20 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(longlong **)(param_1 + 0x138) = plVar11;
        if (plVar14 != (longlong *)0x0) goto LAB_23e12d519;
        iVar9 = 0x1f;
        if (pcVar20 == (code *)0x0) goto LAB_23e12d770;
LAB_23e12d57a:
        pcVar17 = pcVar20;
        pcVar19 = pcVar18;
        if (*(longlong **)(pcVar20 + 0x18) == plVar5) goto LAB_23e12ce73;
        goto LAB_23e12cfcd;
      }
      FUN_23e915740(param_1,&plStack_68,_DAT_23eea8148);
      plStack_b0 = plStack_68;
LAB_23e12d501:
      plVar14 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar11;
      pcVar20 = pcStack_58;
      pcVar18 = pcStack_60;
      if (plVar14 == (longlong *)0x0) {
LAB_23e12d568:
        if (pcVar20 == (code *)0x0) {
LAB_23e12d770:
          iVar9 = 0x1f;
          goto LAB_23e12d5a9;
        }
        iVar9 = 0x1f;
        goto LAB_23e12d57a;
      }
LAB_23e12d519:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 != 0) goto LAB_23e12d568;
      iVar9 = 0x1f;
LAB_23e12d525:
      (**(code **)(plVar14[1] + 0x30))();
      if (pcVar20 != (code *)0x0) goto LAB_23e12d549;
LAB_23e12d7e1:
      if (iVar9 != 0) goto LAB_23e12d5a9;
    }
    else {
      lVar10 = *(longlong *)(pcVar18 + 0x10);
      if (0 < lVar10) {
        lVar12 = 0;
        do {
          if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar18 + lVar12 * 8 + 0x18) + 8) + 0xa8))
             || ((*(byte *)(*(longlong *)(pcVar18 + lVar12 * 8 + 0x18) + 0xab) & 0x40) == 0))
          goto LAB_23e12d070;
          lVar12 = lVar12 + 1;
        } while (lVar10 != lVar12);
        lVar12 = 0;
        do {
          iVar9 = FUN_23a35ebd0(param_1,pcVar17,*(undefined8 *)(pcVar18 + lVar12 * 8 + 0x18));
          if (iVar9 != 0) goto LAB_23e12d0fb;
          lVar12 = lVar12 + 1;
        } while (lVar10 != lVar12);
        goto LAB_23e12ce00;
      }
LAB_23e12ce07:
      if ((pcVar19 == pcVar20) || (pcVar19 == (code *)0x0)) {
        plStack_b0 = *(longlong **)PyExc_RuntimeError_exref;
        pcVar18 = (code *)PyUnicode_FromString("No active exception to reraise");
        *plStack_b0 = *plStack_b0 + 1;
        pcVar19 = *(code **)(param_1 + 0x138);
        iVar9 = 0x1c;
        iVar21 = 0x1c;
        *(longlong **)(param_1 + 0x138) = plVar11;
        if ((pcVar19 == (code *)0x0) ||
           (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 != 0))
        goto LAB_23e12d5a9;
LAB_23e12d7d0:
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
        iVar9 = iVar21;
        goto LAB_23e12d7e1;
      }
      plStack_b0 = *(longlong **)(pcVar19 + 8);
      pcVar20 = *(code **)(pcVar19 + 0x28);
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      *plStack_b0 = *plStack_b0 + 1;
      pcVar18 = pcVar19;
      if (pcVar20 != (code *)0x0) {
        *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
        if (plVar5 == *(longlong **)(pcVar20 + 0x18)) {
          *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar20 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar11;
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
        if (*(longlong *)pcVar19 == 0) {
          (*(code *)plStack_b0[6])(pcVar19);
          iVar9 = 0;
LAB_23e12d549:
          pcVar17 = pcVar20;
          pcVar19 = pcVar18;
          if (plVar5 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23e12ce73;
          if (iVar9 != 0) goto LAB_23e12cfcd;
        }
        else {
          pcVar17 = pcVar20;
          if (*(longlong **)(pcVar20 + 0x18) == plVar5) goto LAB_23e12ce73;
        }
        iVar9 = (int)plVar5[5];
        goto LAB_23e12cfcd;
      }
      *(longlong **)(param_1 + 0x138) = plVar11;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        iVar21 = 0;
        goto LAB_23e12d7d0;
      }
    }
    iVar9 = (int)plVar5[5];
  }
LAB_23e12d5a9:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar17 + 0x18) = plVar5;
  *(longlong *)(pcVar17 + 0x10) = 0;
  *plVar5 = *plVar5 + 1;
  lVar10 = *(longlong *)(pcStack_a8 + 0x1f8);
  *(int *)(pcVar17 + 0x24) = iVar9;
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar12 = *(longlong *)(pcVar17 + -8);
  puVar4 = *(undefined8 **)(lVar10 + 8);
  *puVar4 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar10;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar4;
  *(code **)(lVar10 + 8) = pcVar17 + -0x10;
  pcVar19 = pcVar18;
LAB_23e12ce73:
  FUN_23e8bba40(plVar5,&DAT_23ec5a10f,plVar1,plVar2,plVar3);
  if (_DAT_23eeaadf0 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeaadf0 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar10 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  plVar5 = (longlong *)plVar11[2];
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
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plStack_b0,pcVar19,pcVar17);
  return (code *)0x0;
}
