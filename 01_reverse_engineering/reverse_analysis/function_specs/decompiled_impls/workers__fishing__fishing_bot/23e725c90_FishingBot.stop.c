/* ===== 23e725c90 workers.fishing.fishing_bot:FishingBot.stop ===== */
/* ghidra_name=FUN_23e725c90 entry=23e725c90 size=3828 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e725c90(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  bool bVar7;
  code *pcVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong *plVar17;
  longlong *plVar18;
  code *pcVar19;
  code *pcVar20;
  code *pcVar21;
  code *pcVar22;
  code *pcVar23;
  undefined4 uVar24;
  int iStack_a0;
  undefined1 auStack_88 [16];
  code *apcStack_78 [2];
  code *pcStack_68;
  code *pcStack_60;
  code *pcStack_58;
  
  plVar10 = _DAT_23eedae68;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedae68 == (longlong *)0x0) {
LAB_23e725ccd:
    _DAT_23eedae68 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf48,DAT_23eedaeb8,8);
  }
  else {
    lVar2 = *_DAT_23eedae68;
    if (1 < lVar2) {
      *_DAT_23eedae68 = lVar2 + -1;
      goto LAB_23e725ccd;
    }
    if (_DAT_23eedae68[2] != 0) {
      *_DAT_23eedae68 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e725ccd;
    }
  }
  plVar3 = _DAT_23eedae68;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedae68 + 9;
  lVar15 = *(longlong *)(lVar2 + 8);
  _DAT_23eedae68[0xf] = lVar15;
  *(longlong **)(lVar2 + 8) = plVar10;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar16 = DAT_23eed8ab8;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar16);
  if (plVar10 == (longlong *)0x0) {
    pcVar14 = *(code **)(param_1 + 0x60);
    pcVar23 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar21 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e72669c:
    if (pcVar23 != (code *)0x0) {
      uVar24 = 0x11b;
      pcVar19 = pcVar23;
      if (*(longlong **)(pcVar23 + 0x18) == plVar3) goto LAB_23e726000;
LAB_23e725f59:
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
      *(longlong **)(pcVar19 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar2 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      *(undefined4 *)(pcVar19 + 0x24) = uVar24;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar15 = *(longlong *)(pcVar19 + -8);
      puVar4 = *(undefined8 **)(lVar2 + 8);
      *puVar4 = pcVar19 + -0x10;
      *(longlong *)(pcVar19 + -0x10) = lVar2;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
      lVar15 = *(longlong *)pcVar23;
      *(code **)(lVar2 + 8) = pcVar19 + -0x10;
      *(code **)(pcVar19 + 0x10) = pcVar23;
      if (lVar15 == 0) {
        (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
      }
      goto LAB_23e726000;
    }
LAB_23e7266a2:
    uVar24 = 0x11b;
  }
  else {
    plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd90);
    if (plVar11 == (longlong *)0x0) {
LAB_23e725f0c:
      pcVar14 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto joined_r0x00023e72669c;
    }
    *(undefined4 *)(plVar3 + 5) = 0x11b;
    plVar12 = (longlong *)FUN_23e91a870(param_1,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e725f0c;
    plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd98);
    if (plVar11 == (longlong *)0x0) {
      pcVar14 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        iStack_a0 = 0x11b;
        goto LAB_23e726828;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        iStack_a0 = 0x11b;
        goto LAB_23e7263e2;
      }
      if (pcVar23 != (code *)0x0) {
        pcVar19 = pcVar23;
        if (plVar3 == *(longlong **)(pcVar23 + 0x18)) goto LAB_23e726000;
        goto LAB_23e726b1b;
      }
      goto LAB_23e7266a2;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8ac0);
    if (plVar13 == (longlong *)0x0) {
LAB_23e7260d0:
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcVar14 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plVar13 != (longlong *)0x0) {
        *plVar13 = *plVar13 + 1;
      }
      pcVar21 = DAT_23ed6a4f8;
      apcStack_78[0] = pcVar14;
      if (pcVar14 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar14 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar14;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar21 + 0x10) = 0;
        *(longlong **)(pcVar21 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        *(longlong *)(pcVar21 + 0x20) = 0x11cffffffff;
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8)
        ;
        lVar15 = *(longlong *)(pcVar21 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar21 + -0x10;
        *(longlong *)(pcVar21 + -0x10) = lVar2;
        *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar21 + -0x10;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))(apcStack_78[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar23 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar23;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar21 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        *(longlong *)(pcVar21 + 0x20) = 0x11cffffffff;
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8)
        ;
        lVar15 = *(longlong *)(pcVar21 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar21 + -0x10;
        *(longlong *)(pcVar21 + -0x10) = lVar2;
        *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar21 + -0x10;
        *(code **)(pcVar21 + 0x10) = pcVar14;
        *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
        if ((apcStack_78[0] != (code *)0x0) &&
           (*(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + -1,
           *(longlong *)apcStack_78[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_78[0] + 8) + 0x30))();
        }
      }
      pcVar14 = _Py_NoneStruct_exref;
      apcStack_78[0] = pcVar21;
      if (((code *)auStack_88._0_8_ != (code *)0x0) &&
         ((code *)auStack_88._0_8_ != _Py_NoneStruct_exref)) {
        FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,apcStack_78);
      }
      plVar18 = *(longlong **)(auStack_88._8_8_ + 0x28);
      if (apcStack_78[0] == pcVar14) {
        pcVar21 = (code *)0x0;
      }
      else {
        pcVar21 = apcStack_78[0];
        if (apcStack_78[0] != (code *)0x0) {
          *(longlong *)apcStack_78[0] = *(longlong *)apcStack_78[0] + 1;
        }
      }
      *(code **)(auStack_88._8_8_ + 0x28) = pcVar21;
      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
        (**(code **)(plVar18[1] + 0x30))();
      }
      plVar18 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = auStack_88._8_8_;
      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
        (**(code **)(plVar18[1] + 0x30))();
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
      pcVar21 = *(code **)PyExc_BaseException_exref;
      pcVar23 = *(code **)(pcVar19 + 8);
      if ((*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) & 0x4000000) == 0) {
        if (((int)*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) < 0) &&
           (((byte)pcVar21[0xab] & 0x40) != 0)) {
          pcVar22 = *(code **)(pcVar23 + 8);
          if ((*(uint *)(pcVar22 + 0xa8) & 0x40000000) == 0) {
            pcVar20 = pcVar23;
            if ((-1 < (int)*(uint *)(pcVar22 + 0xa8)) ||
               (pcVar22 = pcVar23, ((byte)pcVar23[0xab] & 0x40) == 0)) goto LAB_23e7269ac;
          }
          else {
            pcVar20 = pcVar22;
            if (-1 < *(int *)(*(longlong *)(pcVar22 + 8) + 0xa8)) {
LAB_23e7269ac:
              if (pcVar21 == pcVar20) goto LAB_23e7264cd;
              goto LAB_23e726323;
            }
          }
          lVar2 = *(longlong *)(pcVar22 + 0x158);
          if (lVar2 == 0) {
            do {
              if (pcVar21 == pcVar22) goto LAB_23e7265f7;
              pcVar22 = *(code **)(pcVar22 + 0x100);
            } while (pcVar22 != (code *)0x0);
            if (pcVar21 == PyBaseObject_Type_exref) goto LAB_23e7265f7;
          }
          else if (0 < *(longlong *)(lVar2 + 0x10)) {
            lVar15 = 0;
            do {
              if (pcVar21 == *(code **)(lVar2 + 0x18 + lVar15 * 8)) goto LAB_23e7265f7;
              lVar15 = lVar15 + 1;
            } while (*(longlong *)(lVar2 + 0x10) != lVar15);
          }
          goto LAB_23e726323;
        }
LAB_23e726430:
        plVar18 = *(longlong **)PyExc_TypeError_exref;
        uVar16 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar5 = *(longlong **)(param_1 + 0x60);
        plVar6 = *(longlong **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x68);
        *(longlong **)(param_1 + 0x60) = plVar18;
        *plVar18 = *plVar18 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar16;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))();
        }
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if ((plVar6 == (longlong *)0x0) || (*plVar6 = *plVar6 + -1, *plVar6 != 0)) {
LAB_23e7265f0:
          pcVar19 = *(code **)(param_1 + 0x138);
LAB_23e7265f7:
          pcVar23 = *(code **)(pcVar19 + 8);
        }
        else {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
          pcVar19 = *(code **)(param_1 + 0x138);
          pcVar23 = *(code **)(pcVar19 + 8);
        }
LAB_23e7264cd:
        pcStack_58 = *(code **)(pcVar19 + 0x28);
        *(undefined4 *)(plVar3 + 5) = 0x11b;
        if (pcStack_58 == (code *)0x0) {
          pcStack_58 = pcVar14;
        }
        pcStack_68 = pcVar23;
        pcStack_60 = pcVar19;
        plVar18 = (longlong *)FUN_23e956150(param_1,plVar11,&pcStack_68);
        if (plVar18 == (longlong *)0x0) {
LAB_23e7267b8:
          pcVar14 = *(code **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x68);
          bVar7 = false;
          pcVar19 = *(code **)(param_1 + 0x138);
          pcVar23 = *(code **)(param_1 + 0x70);
          iStack_a0 = 0x11b;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(longlong **)(param_1 + 0x138) = plVar13;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar22 = pcVar14;
          pcVar20 = pcVar21;
          pcVar8 = pcVar23;
          if (pcVar19 == (code *)0x0) goto LAB_23e7263ae;
        }
        else {
          iVar9 = FUN_23a35f020(plVar18);
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if (iVar9 == -1) goto LAB_23e7267b8;
          if (iVar9 != 0) {
            plVar3 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar13;
            if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
              (**(code **)(plVar3[1] + 0x30))();
            }
            lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar3 = *(longlong **)(lVar2 + 0x28);
            plVar13 = (longlong *)plVar3[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
            *(undefined4 *)(plVar3 + 8) = 0xffffffff;
            if (plVar13 != (longlong *)0x0) {
              plVar3[2] = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
            }
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))(plVar3);
            }
            plVar3[0xf] = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
LAB_23e725ec9:
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar14;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar14;
          }
          pcVar19 = *(code **)(param_1 + 0x138);
          bVar7 = false;
          if ((pcVar19 == pcVar14) || (pcVar19 == (code *)0x0)) {
            pcVar23 = *(code **)PyExc_RuntimeError_exref;
            pcVar14 = pcVar23;
            pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar19 = *(code **)(param_1 + 0x138);
            *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
            *(longlong **)(param_1 + 0x138) = plVar13;
            if (pcVar19 == (code *)0x0) {
              pcStack_58 = (code *)0x0;
              iStack_a0 = 0x11b;
              pcVar23 = (code *)0x0;
              pcVar22 = pcVar14;
              pcVar20 = pcVar21;
              pcVar8 = pcStack_58;
              goto LAB_23e7263ae;
            }
            iStack_a0 = 0x11b;
            pcVar23 = (code *)0x0;
          }
          else {
            pcVar14 = *(code **)(pcVar19 + 8);
            pcVar23 = *(code **)(pcVar19 + 0x28);
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
            *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
            if ((pcVar23 != (code *)0x0) &&
               (*(longlong *)pcVar23 = *(longlong *)pcVar23 + 1,
               plVar3 == *(longlong **)(pcVar23 + 0x18))) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar23 + 0x24);
            }
            iStack_a0 = 0;
            *(longlong **)(param_1 + 0x138) = plVar13;
            pcVar21 = pcVar19;
          }
        }
LAB_23e72637c:
        *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
        if (*(longlong *)pcVar19 == 0) {
          (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
        }
        pcVar22 = pcVar14;
        pcVar20 = pcVar21;
        pcStack_60 = pcVar21;
        pcVar8 = pcVar23;
        pcStack_58 = pcVar23;
        if (!bVar7) goto LAB_23e7263ae;
      }
      else {
        lVar2 = *(longlong *)(pcVar21 + 0x10);
        if (0 < lVar2) {
          lVar15 = 0;
          do {
            if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar21 + lVar15 * 8 + 0x18) + 8) + 0xa8)
                ) || ((*(byte *)(*(longlong *)(pcVar21 + lVar15 * 8 + 0x18) + 0xab) & 0x40) == 0))
            goto LAB_23e726430;
            lVar15 = lVar15 + 1;
          } while (lVar2 != lVar15);
          lVar15 = 0;
          do {
            iVar9 = FUN_23a35ebd0(param_1,pcVar23,*(undefined8 *)(pcVar21 + lVar15 * 8 + 0x18),
                                  pcVar21,pcVar23);
            if (iVar9 != 0) goto LAB_23e7265f0;
            lVar15 = lVar15 + 1;
          } while (lVar2 != lVar15);
          pcVar19 = *(code **)(param_1 + 0x138);
        }
LAB_23e726323:
        if ((pcVar19 != pcVar14) && (pcVar19 != (code *)0x0)) {
          pcVar14 = *(code **)(pcVar19 + 8);
          pcVar23 = *(code **)(pcVar19 + 0x28);
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
          if ((pcVar23 != (code *)0x0) &&
             (*(longlong *)pcVar23 = *(longlong *)pcVar23 + 1,
             plVar3 == *(longlong **)(pcVar23 + 0x18))) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar23 + 0x24);
          }
          iStack_a0 = 0;
          bVar7 = true;
          *(longlong **)(param_1 + 0x138) = plVar13;
          pcVar21 = pcVar19;
          goto LAB_23e72637c;
        }
        pcVar23 = *(code **)PyExc_RuntimeError_exref;
        pcVar14 = pcVar23;
        pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar19 = *(code **)(param_1 + 0x138);
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        *(longlong **)(param_1 + 0x138) = plVar13;
        if (pcVar19 != (code *)0x0) {
          iStack_a0 = 0x11b;
          pcVar23 = (code *)0x0;
          bVar7 = true;
          goto LAB_23e72637c;
        }
        pcStack_58 = (code *)0x0;
        iStack_a0 = 0x11b;
        pcStack_60 = pcVar21;
      }
      *(undefined4 *)(plVar3 + 5) = 0x11b;
      pcStack_68 = pcVar14;
      plVar13 = (longlong *)FUN_23e957a30(param_1,plVar11,DAT_23eed8d60);
      if (plVar13 == (longlong *)0x0) {
        pcVar23 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar14 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        FUN_23a35d6b0(&pcStack_68);
        iStack_a0 = 0x11b;
        pcVar22 = pcStack_68;
        pcVar20 = pcStack_60;
        pcVar8 = pcStack_58;
      }
      else {
        *plVar13 = *plVar13 + -1;
        pcVar23 = pcStack_58;
        pcVar21 = pcStack_60;
        pcVar14 = pcStack_68;
        pcVar22 = pcStack_68;
        pcVar20 = pcStack_60;
        pcVar8 = pcStack_58;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          pcVar23 = pcStack_58;
          pcVar21 = pcStack_60;
          pcVar14 = pcStack_68;
          pcVar22 = pcStack_68;
          pcVar20 = pcStack_60;
          pcVar8 = pcStack_58;
        }
      }
    }
    else {
      pcVar14 = (code *)FUN_23e8d7f30(param_1,plVar13);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (pcVar14 == (code *)0x0) goto LAB_23e7260d0;
      *(undefined4 *)(plVar3 + 5) = 0x11b;
      plVar13 = (longlong *)FUN_23e957a30(param_1,plVar11,DAT_23eed8d60);
      if (plVar13 != (longlong *)0x0) {
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar10 = *(longlong **)(lVar2 + 0x28);
        plVar3 = (longlong *)plVar10[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
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
        goto LAB_23e725ec9;
      }
      pcVar14 = *(code **)(param_1 + 0x60);
      iStack_a0 = 0x11b;
      pcVar23 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar22 = pcStack_68;
      pcVar20 = pcStack_60;
      pcVar8 = pcStack_58;
    }
LAB_23e7263ae:
    pcStack_58 = pcVar8;
    pcStack_60 = pcVar20;
    pcStack_68 = pcVar22;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
LAB_23e726828:
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) goto LAB_23e726839;
LAB_23e726843:
      if (plVar11 != (longlong *)0x0) goto LAB_23e7263d0;
    }
    else {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
LAB_23e726839:
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        goto LAB_23e726843;
      }
LAB_23e7263d0:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
LAB_23e7263e2:
    if (pcVar23 != (code *)0x0) {
      pcVar19 = pcVar23;
      if (*(longlong **)(pcVar23 + 0x18) == plVar3) goto LAB_23e726000;
      if (iStack_a0 == 0) {
        uVar24 = (undefined4)plVar3[5];
      }
      else {
LAB_23e726b1b:
        uVar24 = 0x11b;
      }
      goto LAB_23e725f59;
    }
    uVar24 = 0x11b;
    if (iStack_a0 == 0) {
      uVar24 = (undefined4)plVar3[5];
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
  *(longlong *)(pcVar19 + 0x10) = 0;
  *(longlong **)(pcVar19 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar2 = *(longlong *)(pcVar23 + 0x1f8);
  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
  lVar2 = *(longlong *)(lVar2 + 0x10);
  *(undefined4 *)(pcVar19 + 0x24) = uVar24;
  lVar2 = *(longlong *)(lVar2 + 0x2e8);
  lVar15 = *(longlong *)(pcVar19 + -8);
  puVar4 = *(undefined8 **)(lVar2 + 8);
  *puVar4 = pcVar19 + -0x10;
  *(longlong *)(pcVar19 + -0x10) = lVar2;
  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
  *(code **)(lVar2 + 8) = pcVar19 + -0x10;
LAB_23e726000:
  FUN_23e8bba40(plVar3,&DAT_23ec5dc90,plVar1);
  if (_DAT_23eedae68 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedae68 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar2 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
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
  FUN_23a33aa70(param_1,pcVar14,pcVar21,pcVar19);
  return (code *)0x0;
}
