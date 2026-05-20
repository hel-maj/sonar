/* ===== 23e2e6bf0 ui.hotkey_listener:54 ===== */
/* ghidra_name=FUN_23e2e6bf0 entry=23e2e6bf0 size=4310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2e6bf0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  bool bVar11;
  char cVar12;
  int iVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  undefined8 uVar18;
  code *pcVar19;
  code *pcVar20;
  longlong *plVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  code *pcVar25;
  undefined4 uVar26;
  code *pcStack_a8;
  int iStack_a0;
  undefined1 auStack_88 [16];
  code *apcStack_78 [2];
  code *pcStack_68;
  code *pcStack_60;
  code *pcStack_58;
  
  plVar14 = _DAT_23eeb0160;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eeb0160 == (longlong *)0x0) {
LAB_23e2e6c35:
    _DAT_23eeb0160 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0158,DAT_23eeb0170,0x18);
  }
  else {
    lVar4 = *_DAT_23eeb0160;
    if (1 < lVar4) {
      *_DAT_23eeb0160 = lVar4 + -1;
      goto LAB_23e2e6c35;
    }
    if (_DAT_23eeb0160[2] != 0) {
      *_DAT_23eeb0160 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e2e6c35;
    }
  }
  plVar7 = _DAT_23eeb0160;
  lVar4 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eeb0160 + 9;
  lVar17 = *(longlong *)(lVar4 + 8);
  _DAT_23eeb0160[0xf] = lVar17;
  *(longlong **)(lVar4 + 8) = plVar14;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar7[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  uVar18 = _DAT_23eead0d8;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar18);
  if (plVar14 == (longlong *)0x0) {
    pcStack_a8 = *(code **)(param_1 + 0x60);
    pcVar25 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar20 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e2e7624:
    if (pcVar25 == (code *)0x0) {
LAB_23e2e7ae0:
      uVar26 = 0x38;
LAB_23e2e78b2:
      pcVar19 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar25 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar25;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar25 = _PyRuntime_exref;
      *(longlong *)(pcVar19 + 0x10) = 0;
      *(longlong **)(pcVar19 + 0x18) = plVar7;
      *plVar7 = *plVar7 + 1;
      lVar4 = *(longlong *)(pcVar25 + 0x1f8);
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      lVar4 = *(longlong *)(lVar4 + 0x10);
      *(undefined4 *)(pcVar19 + 0x24) = uVar26;
      lVar4 = *(longlong *)(lVar4 + 0x2e8);
      lVar17 = *(longlong *)(pcVar19 + -8);
      puVar6 = *(undefined8 **)(lVar4 + 8);
      *puVar6 = pcVar19 + -0x10;
      *(longlong *)(pcVar19 + -0x10) = lVar4;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
      *(code **)(lVar4 + 8) = pcVar19 + -0x10;
      goto LAB_23e2e7140;
    }
    plVar14 = *(longlong **)(pcVar25 + 0x18);
joined_r0x00023e2e7633:
    uVar26 = 0x38;
    pcVar19 = pcVar25;
    if (plVar14 == plVar7) goto LAB_23e2e7140;
  }
  else {
    plVar15 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd90);
    if (plVar15 == (longlong *)0x0) {
LAB_23e2e7046:
      pcStack_a8 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      pcVar25 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 != 0) goto joined_r0x00023e2e7624;
      (**(code **)(plVar14[1] + 0x30))(plVar14);
      if (pcVar25 == (code *)0x0) goto LAB_23e2e7ae0;
      plVar14 = *(longlong **)(pcVar25 + 0x18);
      goto joined_r0x00023e2e7633;
    }
    *(undefined4 *)(plVar7 + 5) = 0x38;
    plVar16 = (longlong *)FUN_23e91a870(param_1,plVar15);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (plVar16 == (longlong *)0x0) goto LAB_23e2e7046;
    plVar15 = (longlong *)FUN_23e8d9880(plVar14,DAT_23ed6cd98);
    if (plVar15 == (longlong *)0x0) {
      pcStack_a8 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      pcVar25 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        iStack_a0 = 0x38;
        goto LAB_23e2e7873;
      }
      lVar4 = *plVar16;
      *plVar16 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
        iStack_a0 = 0x38;
        goto LAB_23e2e780d;
      }
      if (pcVar25 != (code *)0x0) {
        pcVar19 = pcVar25;
        if (plVar7 == *(longlong **)(pcVar25 + 0x18)) goto LAB_23e2e7140;
        goto LAB_23e2e7bfb;
      }
      goto LAB_23e2e7ae0;
    }
    cVar12 = FUN_23e8d9ac0(plVar1,_DAT_23eead0a8,plVar2);
    if (cVar12 == '\0') {
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      pcVar25 = *(code **)(param_1 + 0x70);
      uVar26 = 0x39;
LAB_23e2e6d69:
      plVar5 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plVar5 != (longlong *)0x0) {
        *plVar5 = *plVar5 + 1;
      }
      pcVar20 = DAT_23ed6a4f8;
      apcStack_78[0] = pcVar25;
      if (pcVar25 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar25 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar25;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar25 = _PyRuntime_exref;
        *(longlong **)(pcVar20 + 0x18) = plVar7;
        *(longlong *)(pcVar20 + 0x10) = 0;
        *plVar7 = *plVar7 + 1;
        lVar4 = *(longlong *)(pcVar25 + 0x1f8);
        *(undefined4 *)(pcVar20 + 0x24) = uVar26;
        *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
        lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x2e8);
        lVar17 = *(longlong *)(pcVar20 + -8);
        puVar6 = *(undefined8 **)(lVar4 + 8);
        *puVar6 = pcVar20 + -0x10;
        *(longlong *)(pcVar20 + -0x10) = lVar4;
        *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
        *(code **)(lVar4 + 8) = pcVar20 + -0x10;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))(apcStack_78[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar19 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar19;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar19 = _PyRuntime_exref;
        *(longlong **)(pcVar20 + 0x18) = plVar7;
        *plVar7 = *plVar7 + 1;
        lVar4 = *(longlong *)(pcVar19 + 0x1f8);
        *(undefined4 *)(pcVar20 + 0x24) = uVar26;
        *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
        lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x2e8);
        lVar17 = *(longlong *)(pcVar20 + -8);
        puVar6 = *(undefined8 **)(lVar4 + 8);
        *puVar6 = pcVar20 + -0x10;
        *(longlong *)(pcVar20 + -0x10) = lVar4;
        *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
        *(code **)(lVar4 + 8) = pcVar20 + -0x10;
        *(code **)(pcVar20 + 0x10) = pcVar25;
        *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))();
        }
      }
      pcVar25 = _Py_NoneStruct_exref;
      apcStack_78[0] = pcVar20;
      if (((code *)auStack_88._0_8_ != (code *)0x0) &&
         ((code *)auStack_88._0_8_ != _Py_NoneStruct_exref)) {
        FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,apcStack_78);
      }
      plVar21 = *(longlong **)(auStack_88._8_8_ + 0x28);
      if (apcStack_78[0] == pcVar25) {
        pcVar20 = (code *)0x0;
      }
      else {
        pcVar20 = apcStack_78[0];
        if (apcStack_78[0] != (code *)0x0) {
          *(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + 1;
        }
      }
      *(code **)(auStack_88._8_8_ + 0x28) = pcVar20;
      if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
        (**(code **)(plVar21[1] + 0x30))();
      }
      plVar21 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_88._8_8_;
      if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
        (**(code **)(plVar21[1] + 0x30))();
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
      pcVar24 = *(code **)(param_1 + 0x138);
      apcStack_78[0] = (code *)0x0;
      auStack_88 = (undefined1  [16])0x0;
      pcVar20 = *(code **)PyExc_BaseException_exref;
      pcVar19 = *(code **)(pcVar24 + 8);
      if ((*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) & 0x4000000) == 0) {
        if (((int)*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) < 0) &&
           (((byte)pcVar20[0xab] & 0x40) != 0)) {
          pcVar23 = *(code **)(pcVar19 + 8);
          if ((*(uint *)(pcVar23 + 0xa8) & 0x40000000) == 0) {
            pcVar22 = pcVar19;
            if ((-1 < (int)*(uint *)(pcVar23 + 0xa8)) ||
               (pcVar23 = pcVar19, ((byte)pcVar19[0xab] & 0x40) == 0)) goto LAB_23e2e7b75;
          }
          else {
            pcVar22 = pcVar23;
            if (-1 < *(int *)(*(longlong *)(pcVar23 + 8) + 0xa8)) {
LAB_23e2e7b75:
              if (pcVar20 == pcVar22) goto LAB_23e2e731b;
              goto LAB_23e2e6fc7;
            }
          }
          lVar4 = *(longlong *)(pcVar23 + 0x158);
          if (lVar4 == 0) {
            do {
              if (pcVar20 == pcVar23) goto LAB_23e2e7316;
              pcVar23 = *(code **)(pcVar23 + 0x100);
            } while (pcVar23 != (code *)0x0);
            if (pcVar20 == PyBaseObject_Type_exref) goto LAB_23e2e7316;
          }
          else if (0 < *(longlong *)(lVar4 + 0x10)) {
            lVar17 = 0;
            do {
              if (pcVar20 == *(code **)(lVar4 + 0x18 + lVar17 * 8)) goto LAB_23e2e7316;
              lVar17 = lVar17 + 1;
            } while (*(longlong *)(lVar4 + 0x10) != lVar17);
          }
          goto LAB_23e2e6fc7;
        }
LAB_23e2e7260:
        plVar21 = *(longlong **)PyExc_TypeError_exref;
        uVar18 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar8 = *(longlong **)(param_1 + 0x60);
        plVar9 = *(longlong **)(param_1 + 0x70);
        plVar10 = *(longlong **)(param_1 + 0x68);
        *(longlong **)(param_1 + 0x60) = plVar21;
        *plVar21 = *plVar21 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar18;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((plVar9 == (longlong *)0x0) || (*plVar9 = *plVar9 + -1, *plVar9 != 0)) {
LAB_23e2e730f:
          pcVar24 = *(code **)(param_1 + 0x138);
LAB_23e2e7316:
          pcVar19 = *(code **)(pcVar24 + 8);
        }
        else {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          pcVar24 = *(code **)(param_1 + 0x138);
          pcVar19 = *(code **)(pcVar24 + 8);
        }
LAB_23e2e731b:
        pcStack_58 = *(code **)(pcVar24 + 0x28);
        *(undefined4 *)(plVar7 + 5) = 0x38;
        if (pcStack_58 == (code *)0x0) {
          pcStack_58 = pcVar25;
        }
        pcStack_68 = pcVar19;
        pcStack_60 = pcVar24;
        plVar21 = (longlong *)FUN_23e956150(param_1,plVar15,&pcStack_68);
        if (plVar21 == (longlong *)0x0) {
LAB_23e2e7730:
          pcStack_a8 = *(code **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          bVar11 = false;
          pcVar24 = *(code **)(param_1 + 0x138);
          pcVar25 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(longlong **)(param_1 + 0x138) = plVar5;
          iStack_a0 = 0x38;
          pcVar19 = pcStack_a8;
          pcVar23 = pcVar20;
          pcVar22 = pcVar25;
          if (pcVar24 == (code *)0x0) goto LAB_23e2e77b3;
        }
        else {
          iVar13 = FUN_23a35f020(plVar21);
          *plVar21 = *plVar21 + -1;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
          if (iVar13 == -1) goto LAB_23e2e7730;
          if (iVar13 != 0) {
            plVar21 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar5;
            if (plVar21 == (longlong *)0x0) goto LAB_23e2e73b2;
            *plVar21 = *plVar21 + -1;
            lVar4 = *plVar21;
joined_r0x00023e2e7d26:
            if (lVar4 == 0) {
              (**(code **)(plVar21[1] + 0x30))();
            }
LAB_23e2e73b2:
            lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar7 = *(longlong **)(lVar4 + 0x28);
            plVar21 = (longlong *)plVar7[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
            *(undefined4 *)(plVar7 + 8) = 0xffffffff;
            if (plVar21 != (longlong *)0x0) {
              plVar7[2] = 0;
              *plVar21 = *plVar21 + -1;
              if (*plVar21 == 0) {
                (**(code **)(plVar21[1] + 0x30))();
              }
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            plVar7[0xf] = 0;
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            lVar4 = *plVar16;
            *plVar16 = lVar4 + -1;
            if (lVar4 + -1 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            lVar4 = *plVar15;
            *plVar15 = lVar4 + -1;
            if (lVar4 + -1 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
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
              return pcVar25;
            }
            (**(code **)(plVar3[1] + 0x30))(plVar3);
            return pcVar25;
          }
          pcVar24 = *(code **)(param_1 + 0x138);
          bVar11 = false;
          if ((pcVar24 == pcVar25) || (pcVar24 == (code *)0x0)) {
            pcStack_a8 = *(code **)PyExc_RuntimeError_exref;
            pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar24 = *(code **)(param_1 + 0x138);
            *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
            *(longlong **)(param_1 + 0x138) = plVar5;
            if (pcVar24 == (code *)0x0) {
              pcVar25 = (code *)0x0;
              pcStack_58 = (code *)0x0;
              iStack_a0 = 0x38;
              pcVar19 = pcStack_a8;
              pcVar23 = pcVar20;
              pcVar22 = pcStack_58;
              goto LAB_23e2e77b3;
            }
            iStack_a0 = 0x38;
            pcVar25 = (code *)0x0;
          }
          else {
            pcStack_a8 = *(code **)(pcVar24 + 8);
            pcVar25 = *(code **)(pcVar24 + 0x28);
            *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
            *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
            if ((pcVar25 != (code *)0x0) &&
               (*(longlong *)pcVar25 = *(longlong *)pcVar25 + 1,
               plVar7 == *(longlong **)(pcVar25 + 0x18))) {
              *(undefined4 *)(plVar7 + 5) = *(undefined4 *)(pcVar25 + 0x24);
            }
            iStack_a0 = 0;
            *(longlong **)(param_1 + 0x138) = plVar5;
            pcVar20 = pcVar24;
          }
        }
LAB_23e2e7777:
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
        if (*(longlong *)pcVar24 == 0) {
          (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))();
        }
        pcStack_68 = pcStack_a8;
        pcVar19 = pcStack_68;
        pcVar23 = pcVar20;
        pcStack_60 = pcVar20;
        pcVar22 = pcVar25;
        pcStack_58 = pcVar25;
        if (!bVar11) goto LAB_23e2e77b3;
      }
      else {
        lVar4 = *(longlong *)(pcVar20 + 0x10);
        if (0 < lVar4) {
          lVar17 = 0;
          do {
            if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar20 + lVar17 * 8 + 0x18) + 8) + 0xa8)
                ) || ((*(byte *)(*(longlong *)(pcVar20 + lVar17 * 8 + 0x18) + 0xab) & 0x40) == 0))
            goto LAB_23e2e7260;
            lVar17 = lVar17 + 1;
          } while (lVar4 != lVar17);
          lVar17 = 0;
          do {
            iVar13 = FUN_23a35ebd0(param_1,pcVar19,*(undefined8 *)(pcVar20 + lVar17 * 8 + 0x18));
            if (iVar13 != 0) goto LAB_23e2e730f;
            lVar17 = lVar17 + 1;
          } while (lVar4 != lVar17);
          pcVar24 = *(code **)(param_1 + 0x138);
        }
LAB_23e2e6fc7:
        if ((pcVar24 != pcVar25) && (pcVar24 != (code *)0x0)) {
          pcStack_a8 = *(code **)(pcVar24 + 8);
          pcVar25 = *(code **)(pcVar24 + 0x28);
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
          if ((pcVar25 != (code *)0x0) &&
             (*(longlong *)pcVar25 = *(longlong *)pcVar25 + 1,
             plVar7 == *(longlong **)(pcVar25 + 0x18))) {
            *(undefined4 *)(plVar7 + 5) = *(undefined4 *)(pcVar25 + 0x24);
          }
          iStack_a0 = 0;
          bVar11 = true;
          *(longlong **)(param_1 + 0x138) = plVar5;
          pcVar20 = pcVar24;
          goto LAB_23e2e7777;
        }
        pcStack_a8 = *(code **)PyExc_RuntimeError_exref;
        pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar24 = *(code **)(param_1 + 0x138);
        *(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + 1;
        *(longlong **)(param_1 + 0x138) = plVar5;
        if (pcVar24 != (code *)0x0) {
          iStack_a0 = 0x38;
          pcVar25 = (code *)0x0;
          bVar11 = true;
          goto LAB_23e2e7777;
        }
        pcStack_58 = (code *)0x0;
        iStack_a0 = 0x38;
        pcStack_60 = pcVar20;
      }
      *(undefined4 *)(plVar7 + 5) = 0x38;
      pcStack_68 = pcStack_a8;
      plVar21 = (longlong *)FUN_23e957a30(param_1,plVar15,_DAT_23eead100);
      if (plVar21 == (longlong *)0x0) {
        pcVar25 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_a8 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        FUN_23a35d6b0(&pcStack_68);
        iStack_a0 = 0x38;
        pcVar19 = pcStack_68;
        pcVar23 = pcStack_60;
        pcVar22 = pcStack_58;
      }
      else {
        *plVar21 = *plVar21 + -1;
        if (*plVar21 == 0) {
          (**(code **)(plVar21[1] + 0x30))(plVar21);
        }
        pcStack_a8 = pcStack_68;
        pcVar20 = pcStack_60;
        pcVar25 = pcStack_58;
        pcVar19 = pcStack_68;
        pcVar23 = pcStack_60;
        pcVar22 = pcStack_58;
      }
    }
    else {
      cVar12 = FUN_23e8d9ac0(plVar1,_DAT_23eead0b0,plVar3);
      if (cVar12 == '\0') {
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar25 = *(code **)(param_1 + 0x70);
        uVar26 = 0x3a;
        goto LAB_23e2e6d69;
      }
      *(undefined4 *)(plVar7 + 5) = 0x3b;
      plVar21 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23eead0f8,plVar2);
      if (plVar21 == (longlong *)0x0) {
LAB_23e2e75cc:
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar25 = *(code **)(param_1 + 0x70);
        uVar26 = 0x3b;
        goto LAB_23e2e6d69;
      }
      cVar12 = FUN_23e8d9ac0(plVar1,_DAT_23eead0f0,plVar21);
      *plVar21 = *plVar21 + -1;
      if (*plVar21 == 0) {
        (**(code **)(plVar21[1] + 0x30))(plVar21);
      }
      if (cVar12 == '\0') goto LAB_23e2e75cc;
      cVar12 = FUN_23e8d9ac0(plVar1,DAT_23eead0e0,_Py_FalseStruct_exref);
      if (cVar12 == '\0') {
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar25 = *(code **)(param_1 + 0x70);
        uVar26 = 0x3c;
        goto LAB_23e2e6d69;
      }
      *(undefined4 *)(plVar7 + 5) = 0x38;
      plVar21 = (longlong *)FUN_23e957a30(param_1,plVar15,_DAT_23eead100);
      if (plVar21 != (longlong *)0x0) {
        *plVar21 = *plVar21 + -1;
        lVar4 = *plVar21;
        pcVar25 = _Py_NoneStruct_exref;
        goto joined_r0x00023e2e7d26;
      }
      pcStack_a8 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      iStack_a0 = 0x38;
      pcVar25 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar19 = pcStack_68;
      pcVar23 = pcStack_60;
      pcVar22 = pcStack_58;
    }
LAB_23e2e77b3:
    pcStack_58 = pcVar22;
    pcStack_60 = pcVar23;
    pcStack_68 = pcVar19;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
LAB_23e2e7873:
      (**(code **)(plVar14[1] + 0x30))(plVar14);
      lVar4 = *plVar16;
      *plVar16 = lVar4 + -1;
      if (lVar4 + -1 == 0) goto LAB_23e2e77d6;
LAB_23e2e77e2:
      if (plVar15 != (longlong *)0x0) goto LAB_23e2e77ea;
    }
    else {
      lVar4 = *plVar16;
      *plVar16 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
LAB_23e2e77d6:
        (**(code **)(plVar16[1] + 0x30))();
        goto LAB_23e2e77e2;
      }
LAB_23e2e77ea:
      lVar4 = *plVar15;
      *plVar15 = lVar4 + -1;
      if (lVar4 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
    }
LAB_23e2e780d:
    if (pcVar25 == (code *)0x0) {
      uVar26 = 0x38;
      if (iStack_a0 == 0) {
        uVar26 = (undefined4)plVar7[5];
      }
      goto LAB_23e2e78b2;
    }
    pcVar19 = pcVar25;
    if (*(longlong **)(pcVar25 + 0x18) == plVar7) goto LAB_23e2e7140;
    if (iStack_a0 == 0) {
      uVar26 = (undefined4)plVar7[5];
    }
    else {
LAB_23e2e7bfb:
      uVar26 = 0x38;
    }
  }
  pcVar19 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar23 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar23;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar23 = _PyRuntime_exref;
  *(longlong **)(pcVar19 + 0x18) = plVar7;
  *plVar7 = *plVar7 + 1;
  lVar4 = *(longlong *)(pcVar23 + 0x1f8);
  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar19 + 0x24) = uVar26;
  lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x2e8);
  lVar17 = *(longlong *)(pcVar19 + -8);
  puVar6 = *(undefined8 **)(lVar4 + 8);
  *puVar6 = pcVar19 + -0x10;
  *(longlong *)(pcVar19 + -0x10) = lVar4;
  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar6;
  lVar17 = *(longlong *)pcVar25;
  *(code **)(lVar4 + 8) = pcVar19 + -0x10;
  *(code **)(pcVar19 + 0x10) = pcVar25;
  if (lVar17 == 0) {
    (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
  }
LAB_23e2e7140:
  FUN_23e8bba40(plVar7,&DAT_23ec5b355,plVar1,plVar2,plVar3);
  if (_DAT_23eeb0160 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eeb0160 = (longlong *)0x0;
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar14 = *(longlong **)(lVar4 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
  plVar7 = (longlong *)plVar14[2];
  *(undefined4 *)(plVar14 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar14[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  plVar14[0xf] = 0;
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
  FUN_23a33aa70(param_1,pcStack_a8,pcVar20,pcVar19);
  return (code *)0x0;
}
