/* ===== 23e2e7d90 ui.hotkey_listener:62 ===== */
/* ghidra_name=FUN_23e2e7d90 entry=23e2e7d90 size=4048 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2e7d90(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  bool bVar8;
  bool bVar9;
  code *pcVar10;
  char cVar11;
  int iVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined8 uVar17;
  longlong *plVar18;
  code *pcVar19;
  code *pcVar20;
  longlong *plVar21;
  code *pcVar22;
  code *pcVar23;
  code *pcVar24;
  undefined4 uVar25;
  code *pcVar26;
  undefined1 auStack_88 [16];
  code *apcStack_78 [2];
  code *pcStack_68;
  code *pcStack_60;
  code *pcStack_58;
  
  plVar13 = _DAT_23eeb0150;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb0150 == (longlong *)0x0) {
LAB_23e2e7dcd:
    _DAT_23eeb0150 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0148,DAT_23eeb0170,8);
  }
  else {
    lVar2 = *_DAT_23eeb0150;
    if (1 < lVar2) {
      *_DAT_23eeb0150 = lVar2 + -1;
      goto LAB_23e2e7dcd;
    }
    if (_DAT_23eeb0150[2] != 0) {
      *_DAT_23eeb0150 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      goto LAB_23e2e7dcd;
    }
  }
  plVar5 = _DAT_23eeb0150;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar13 = _DAT_23eeb0150 + 9;
  lVar16 = *(longlong *)(lVar2 + 8);
  _DAT_23eeb0150[0xf] = lVar16;
  *(longlong **)(lVar2 + 8) = plVar13;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar5[0xe] != 0)))) {
    plVar13 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar13;
    if (plVar13 != (longlong *)0x0) {
      *plVar13 = *plVar13 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar17 = _DAT_23eead0d8;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,uVar17);
  if (plVar13 == (longlong *)0x0) {
    pcVar26 = *(code **)(param_1 + 0x60);
    pcVar24 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar20 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar24 != (code *)0x0) {
      plVar13 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023e2e8774:
      uVar25 = 0x40;
      pcVar19 = pcVar24;
      if (plVar13 == plVar5) goto LAB_23e2e82a0;
LAB_23e2e8200:
      pcVar19 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar22 = _PyRuntime_exref;
      *(longlong **)(pcVar19 + 0x18) = plVar5;
      *plVar5 = *plVar5 + 1;
      lVar2 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      *(undefined4 *)(pcVar19 + 0x24) = uVar25;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar16 = *(longlong *)(pcVar19 + -8);
      puVar4 = *(undefined8 **)(lVar2 + 8);
      *puVar4 = pcVar19 + -0x10;
      *(longlong *)(pcVar19 + -0x10) = lVar2;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
      lVar16 = *(longlong *)pcVar24;
      *(code **)(lVar2 + 8) = pcVar19 + -0x10;
      *(code **)(pcVar19 + 0x10) = pcVar24;
      if (lVar16 == 0) {
        (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
      }
      goto LAB_23e2e82a0;
    }
LAB_23e2e8ba0:
    uVar25 = 0x40;
  }
  else {
    plVar14 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd90);
    if (plVar14 == (longlong *)0x0) {
LAB_23e2e81bc:
      pcVar26 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (pcVar24 != (code *)0x0) {
        plVar13 = *(longlong **)(pcVar24 + 0x18);
        goto joined_r0x00023e2e8774;
      }
      goto LAB_23e2e8ba0;
    }
    *(undefined4 *)(plVar5 + 5) = 0x40;
    plVar15 = (longlong *)FUN_23e91a870(param_1,plVar14);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (plVar15 == (longlong *)0x0) goto LAB_23e2e81bc;
    plVar14 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd98);
    pcVar26 = _Py_NoneStruct_exref;
    if (plVar14 == (longlong *)0x0) {
      pcVar26 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        bVar9 = true;
        goto LAB_23e2e8968;
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        bVar9 = true;
        goto LAB_23e2e8932;
      }
      if (pcVar24 == (code *)0x0) goto LAB_23e2e8ba0;
      pcVar19 = pcVar24;
      if (plVar5 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23e2e82a0;
LAB_23e2e8c33:
      uVar25 = 0x40;
      goto LAB_23e2e8200;
    }
    cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eead0a8,_Py_NoneStruct_exref);
    if (cVar11 == '\0') {
      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      uVar25 = 0x41;
      pcVar24 = _PyRuntime_exref;
LAB_23e2e7f08:
      plVar3 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plVar3 != (longlong *)0x0) {
        *plVar3 = *plVar3 + 1;
      }
      pcVar19 = DAT_23ed6a4f8;
      apcStack_78[0] = pcVar20;
      if (pcVar20 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar20 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar20;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar19 + 0x10) = 0;
        *(longlong **)(pcVar19 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        lVar2 = *(longlong *)(pcVar24 + 0x1f8);
        *(undefined4 *)(pcVar19 + 0x24) = uVar25;
        lVar2 = *(longlong *)(lVar2 + 0x10);
        *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
        lVar2 = *(longlong *)(lVar2 + 0x2e8);
        lVar16 = *(longlong *)(pcVar19 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar2;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar19 + -0x10;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))(apcStack_78[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar22 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar22;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar19 + 0x18) = plVar5;
        *plVar5 = *plVar5 + 1;
        lVar2 = *(longlong *)(pcVar24 + 0x1f8);
        *(undefined4 *)(pcVar19 + 0x24) = uVar25;
        lVar2 = *(longlong *)(lVar2 + 0x10);
        *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
        lVar2 = *(longlong *)(lVar2 + 0x2e8);
        lVar16 = *(longlong *)(pcVar19 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar2;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar19 + -0x10;
        *(code **)(pcVar19 + 0x10) = pcVar20;
        *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))();
        }
      }
      apcStack_78[0] = pcVar19;
      if (((code *)auStack_88._0_8_ != (code *)0x0) && ((code *)auStack_88._0_8_ != pcVar26)) {
        FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,apcStack_78);
      }
      plVar21 = *(longlong **)(auStack_88._8_8_ + 0x28);
      if (apcStack_78[0] == pcVar26) {
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
      pcVar23 = *(code **)(param_1 + 0x138);
      apcStack_78[0] = (code *)0x0;
      auStack_88 = (undefined1  [16])0x0;
      pcVar20 = *(code **)PyExc_BaseException_exref;
      pcVar24 = *(code **)(pcVar23 + 8);
      if ((*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) & 0x4000000) == 0) {
        if (((int)*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) < 0) &&
           (((byte)pcVar20[0xab] & 0x40) != 0)) {
          pcVar22 = *(code **)(pcVar24 + 8);
          pcVar19 = pcVar22 + 0xa8;
          if ((*(uint *)pcVar19 & 0x40000000) == 0) {
            pcVar22 = pcVar24;
            if (((int)*(uint *)pcVar19 < 0) && (((byte)pcVar24[0xab] & 0x40) != 0)) {
LAB_23e2e8d12:
              lVar2 = *(longlong *)(pcVar22 + 0x158);
              if (lVar2 == 0) {
                do {
                  if (pcVar20 == pcVar22) goto LAB_23e2e8467;
                  pcVar22 = *(code **)(pcVar22 + 0x100);
                } while (pcVar22 != (code *)0x0);
                if (pcVar20 == PyBaseObject_Type_exref) goto LAB_23e2e8467;
              }
              else if (0 < *(longlong *)(lVar2 + 0x10)) {
                lVar16 = 0;
                do {
                  if (pcVar20 == *(code **)(lVar2 + 0x18 + lVar16 * 8)) goto LAB_23e2e8467;
                  lVar16 = lVar16 + 1;
                } while (*(longlong *)(lVar2 + 0x10) != lVar16);
              }
              goto LAB_23e2e8143;
            }
          }
          else if (*(int *)(*(longlong *)(pcVar22 + 8) + 0xa8) < 0) goto LAB_23e2e8d12;
          if (pcVar20 != pcVar22) goto LAB_23e2e8143;
        }
        else {
LAB_23e2e83c0:
          plVar21 = *(longlong **)PyExc_TypeError_exref;
          uVar17 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar6 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          plVar18 = *(longlong **)(param_1 + 0x68);
          *(longlong **)(param_1 + 0x60) = plVar21;
          *plVar21 = *plVar21 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar17;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
            (**(code **)(plVar6[1] + 0x30))();
          }
          if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if ((plVar7 == (longlong *)0x0) || (*plVar7 = *plVar7 + -1, *plVar7 != 0)) {
LAB_23e2e8460:
            pcVar23 = *(code **)(param_1 + 0x138);
LAB_23e2e8467:
            pcVar24 = *(code **)(pcVar23 + 8);
          }
          else {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
            pcVar23 = *(code **)(param_1 + 0x138);
            pcVar24 = *(code **)(pcVar23 + 8);
          }
        }
        pcStack_58 = *(code **)(pcVar23 + 0x28);
        *(undefined4 *)(plVar5 + 5) = 0x40;
        if (pcStack_58 == (code *)0x0) {
          pcStack_58 = pcVar26;
        }
        pcStack_68 = pcVar24;
        pcStack_60 = pcVar23;
        plVar21 = (longlong *)FUN_23e956150(param_1,plVar14,&pcStack_68);
        if (plVar21 != (longlong *)0x0) {
          iVar12 = FUN_23a35f020(plVar21);
          *plVar21 = *plVar21 + -1;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
          if (iVar12 != -1) {
            if (iVar12 != 0) {
              plVar21 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar3;
              if (plVar21 == (longlong *)0x0) goto LAB_23e2e84f3;
              goto LAB_23e2e84e6;
            }
            pcVar23 = *(code **)(param_1 + 0x138);
            bVar8 = false;
            if ((pcVar23 == (code *)0x0) || (pcVar23 == pcVar26)) {
              pcVar24 = *(code **)PyExc_RuntimeError_exref;
              pcVar26 = pcVar24;
              pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar23 = *(code **)(param_1 + 0x138);
              *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
              *(longlong **)(param_1 + 0x138) = plVar3;
              if (pcVar23 == (code *)0x0) {
                pcStack_58 = (code *)0x0;
                bVar9 = true;
                pcVar24 = (code *)0x0;
                pcVar19 = pcVar26;
                pcVar22 = pcVar20;
                pcVar10 = pcStack_58;
                goto LAB_23e2e8909;
              }
              bVar9 = true;
              pcVar24 = (code *)0x0;
            }
            else {
              pcVar26 = *(code **)(pcVar23 + 8);
              pcVar24 = *(code **)(pcVar23 + 0x28);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
              *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
              if ((pcVar24 != (code *)0x0) &&
                 (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
                 plVar5 == *(longlong **)(pcVar24 + 0x18))) {
                *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
              }
              bVar9 = false;
              *(longlong **)(param_1 + 0x138) = plVar3;
              pcVar20 = pcVar23;
            }
            goto LAB_23e2e88d7;
          }
        }
        pcVar26 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x68);
        bVar8 = false;
        pcVar23 = *(code **)(param_1 + 0x138);
        pcVar24 = *(code **)(param_1 + 0x70);
        bVar9 = true;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(longlong **)(param_1 + 0x138) = plVar3;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar19 = pcVar26;
        pcVar22 = pcVar20;
        pcVar10 = pcVar24;
        if (pcVar23 != (code *)0x0) goto LAB_23e2e88d7;
      }
      else {
        lVar2 = *(longlong *)(pcVar20 + 0x10);
        if (0 < lVar2) {
          lVar16 = 0;
          do {
            if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar20 + lVar16 * 8 + 0x18) + 8) + 0xa8)
                ) || ((*(byte *)(*(longlong *)(pcVar20 + lVar16 * 8 + 0x18) + 0xab) & 0x40) == 0))
            goto LAB_23e2e83c0;
            lVar16 = lVar16 + 1;
          } while (lVar2 != lVar16);
          lVar16 = 0;
          do {
            iVar12 = FUN_23a35ebd0(param_1,pcVar24,*(undefined8 *)(pcVar20 + lVar16 * 8 + 0x18),
                                   pcVar20,pcVar24);
            if (iVar12 != 0) goto LAB_23e2e8460;
            lVar16 = lVar16 + 1;
          } while (lVar2 != lVar16);
          pcVar23 = *(code **)(param_1 + 0x138);
        }
LAB_23e2e8143:
        if ((pcVar23 == pcVar26) || (pcVar23 == (code *)0x0)) {
          pcVar24 = *(code **)PyExc_RuntimeError_exref;
          pcVar26 = pcVar24;
          pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar23 = *(code **)(param_1 + 0x138);
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          *(longlong **)(param_1 + 0x138) = plVar3;
          if (pcVar23 != (code *)0x0) {
            bVar9 = true;
            pcVar24 = (code *)0x0;
            bVar8 = true;
            goto LAB_23e2e88d7;
          }
          pcStack_58 = (code *)0x0;
          bVar9 = true;
          pcStack_60 = pcVar20;
        }
        else {
          pcVar26 = *(code **)(pcVar23 + 8);
          pcVar24 = *(code **)(pcVar23 + 0x28);
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
          *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
          if ((pcVar24 != (code *)0x0) &&
             (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
             plVar5 == *(longlong **)(pcVar24 + 0x18))) {
            *(undefined4 *)(plVar5 + 5) = *(undefined4 *)(pcVar24 + 0x24);
          }
          bVar9 = false;
          bVar8 = true;
          *(longlong **)(param_1 + 0x138) = plVar3;
          pcVar20 = pcVar23;
LAB_23e2e88d7:
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
          if (*(longlong *)pcVar23 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))();
          }
          pcVar19 = pcVar26;
          pcVar22 = pcVar20;
          pcStack_60 = pcVar20;
          pcVar10 = pcVar24;
          pcStack_58 = pcVar24;
          if (!bVar8) goto LAB_23e2e8909;
        }
        *(undefined4 *)(plVar5 + 5) = 0x40;
        pcStack_68 = pcVar26;
        plVar21 = (longlong *)FUN_23e957a30(param_1,plVar14,_DAT_23eead100);
        if (plVar21 == (longlong *)0x0) {
          pcVar24 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar26 = *(code **)(param_1 + 0x60);
          pcVar20 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          FUN_23a35d6b0(&pcStack_68);
          bVar9 = true;
          pcVar19 = pcStack_68;
          pcVar22 = pcStack_60;
          pcVar10 = pcStack_58;
        }
        else {
          *plVar21 = *plVar21 + -1;
          pcVar20 = pcStack_60;
          pcVar24 = pcStack_58;
          pcVar26 = pcStack_68;
          pcVar19 = pcStack_68;
          pcVar22 = pcStack_60;
          pcVar10 = pcStack_58;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
            pcVar20 = pcStack_60;
            pcVar24 = pcStack_58;
            pcVar26 = pcStack_68;
            pcVar19 = pcStack_68;
            pcVar22 = pcStack_60;
            pcVar10 = pcStack_58;
          }
        }
      }
    }
    else {
      cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eead0b0,pcVar26);
      if (cVar11 == '\0') {
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar20 = *(code **)(param_1 + 0x70);
        uVar25 = 0x42;
        pcVar24 = _PyRuntime_exref;
        goto LAB_23e2e7f08;
      }
      lVar2 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar2 + 0x1188) == 0) {
        plVar21 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar12 = *(int *)(lVar2 + 0x1188) + -1;
        *(int *)(lVar2 + 0x1188) = iVar12;
        plVar21 = *(longlong **)(lVar2 + 0xf08 + (longlong)iVar12 * 8);
        *plVar21 = 1;
      }
      pcVar24 = _PyRuntime_exref;
      plVar21[2] = 0;
      plVar21[4] = 0;
      lVar2 = *(longlong *)(pcVar24 + 0x1f8);
      plVar21[3] = 0;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar16 = plVar21[-1];
      puVar4 = *(undefined8 **)(lVar2 + 8);
      *puVar4 = plVar21 + -2;
      plVar21[-2] = lVar2;
      plVar21[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar2 + 8) = plVar21 + -2;
      cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eead0f0,plVar21);
      *plVar21 = *plVar21 + -1;
      if (*plVar21 == 0) {
        (**(code **)(plVar21[1] + 0x30))(plVar21);
      }
      if (cVar11 == '\0') {
        auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar20 = *(code **)(param_1 + 0x70);
        uVar25 = 0x43;
        goto LAB_23e2e7f08;
      }
      *(undefined4 *)(plVar5 + 5) = 0x40;
      plVar21 = (longlong *)FUN_23e957a30(param_1,plVar14,_DAT_23eead100);
      if (plVar21 != (longlong *)0x0) {
LAB_23e2e84e6:
        *plVar21 = *plVar21 + -1;
        if (*plVar21 == 0) {
          (**(code **)(plVar21[1] + 0x30))();
        }
LAB_23e2e84f3:
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar5 = *(longlong **)(lVar2 + 0x28);
        plVar21 = (longlong *)plVar5[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
        *(undefined4 *)(plVar5 + 8) = 0xffffffff;
        if (plVar21 != (longlong *)0x0) {
          plVar5[2] = 0;
          *plVar21 = *plVar21 + -1;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))();
          }
        }
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        plVar5[0xf] = 0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar26;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar26;
      }
      pcVar26 = *(code **)(param_1 + 0x60);
      bVar9 = true;
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar20 = *(code **)(param_1 + 0x68);
      pcVar19 = pcStack_68;
      pcVar22 = pcStack_60;
      pcVar10 = pcStack_58;
    }
LAB_23e2e8909:
    pcStack_58 = pcVar10;
    pcStack_60 = pcVar22;
    pcStack_68 = pcVar19;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
LAB_23e2e8968:
      (**(code **)(plVar13[1] + 0x30))(plVar13);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) goto LAB_23e2e8978;
LAB_23e2e8982:
      if (plVar14 != (longlong *)0x0) goto LAB_23e2e8920;
    }
    else {
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
LAB_23e2e8978:
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        goto LAB_23e2e8982;
      }
LAB_23e2e8920:
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
    }
LAB_23e2e8932:
    if (pcVar24 != (code *)0x0) {
      pcVar19 = pcVar24;
      if (*(longlong **)(pcVar24 + 0x18) == plVar5) goto LAB_23e2e82a0;
      if (bVar9) goto LAB_23e2e8c33;
      uVar25 = (undefined4)plVar5[5];
      goto LAB_23e2e8200;
    }
    uVar25 = 0x40;
    if (!bVar9) {
      uVar25 = (undefined4)plVar5[5];
    }
  }
  pcVar19 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar24 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar24;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar24 = _PyRuntime_exref;
  *(longlong *)(pcVar19 + 0x10) = 0;
  *(longlong **)(pcVar19 + 0x18) = plVar5;
  *plVar5 = *plVar5 + 1;
  lVar2 = *(longlong *)(pcVar24 + 0x1f8);
  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
  lVar2 = *(longlong *)(lVar2 + 0x10);
  *(undefined4 *)(pcVar19 + 0x24) = uVar25;
  lVar2 = *(longlong *)(lVar2 + 0x2e8);
  lVar16 = *(longlong *)(pcVar19 + -8);
  puVar4 = *(undefined8 **)(lVar2 + 8);
  *puVar4 = pcVar19 + -0x10;
  *(longlong *)(pcVar19 + -0x10) = lVar2;
  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar4;
  *(code **)(lVar2 + 8) = pcVar19 + -0x10;
LAB_23e2e82a0:
  FUN_23e8bba40(plVar5,&DAT_23ec5b149,plVar1);
  if (_DAT_23eeb0150 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0150 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar13 = *(longlong **)(lVar2 + 0x28);
  plVar5 = (longlong *)plVar13[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar13 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar13[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar13[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,pcVar26,pcVar20,pcVar19);
  return (code *)0x0;
}
