/* ===== 23e7ef2c0 workers.fishing.memory_fish_read:175 ===== */
/* ghidra_name=FUN_23e7ef2c0 entry=23e7ef2c0 size=6050 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7ef2c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  bool bVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  undefined4 uVar19;
  int iStack_d0;
  longlong *plStack_b8;
  code *pcStack_b0;
  code *pcStack_a8;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar10 = _DAT_23eedead0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedead0 == (longlong *)0x0) {
LAB_23e7ef305:
    _DAT_23eedead0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeac8,DAT_23eedebc0,8);
  }
  else {
    lVar15 = *_DAT_23eedead0;
    if (1 < lVar15) {
      *_DAT_23eedead0 = lVar15 + -1;
      goto LAB_23e7ef305;
    }
    if (_DAT_23eedead0[2] != 0) {
      *_DAT_23eedead0 = lVar15 + -1;
      if (lVar15 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7ef305;
    }
  }
  plVar3 = _DAT_23eedead0;
  lVar15 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedead0 + 9;
  lVar2 = *(longlong *)(lVar15 + 8);
  _DAT_23eedead0[0xf] = lVar2;
  *(longlong **)(lVar15 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar6 = _DAT_23eedde88;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar6);
  if (plVar10 == (longlong *)0x0) goto LAB_23e7efac0;
  iVar9 = FUN_23a35f020(plVar10);
  lVar15 = *plVar10 + -1;
  if (iVar9 == -1) {
    plVar11 = *(longlong **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x68);
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar10 = lVar15;
    if (lVar15 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
joined_r0x00023e7f0217:
      if (pcVar18 == (code *)0x0) goto LAB_23e7f0220;
    }
    else {
      uVar19 = 0xb2;
      if (pcVar18 == (code *)0x0) goto LAB_23e7effc0;
    }
    uVar19 = 0xb2;
    plVar10 = *(longlong **)(pcVar18 + 0x18);
joined_r0x00023e7f07cf:
    pcVar16 = pcVar18;
    if (plVar10 == plVar3) goto LAB_23e7efb90;
  }
  else {
    *plVar10 = lVar15;
    if (lVar15 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar9 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
      if (plVar10 == (longlong *)0x0) {
LAB_23e7efac0:
        pcVar18 = *(code **)(param_1 + 0x70);
        plVar11 = *(longlong **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto joined_r0x00023e7f0217;
      }
      *(undefined4 *)(plVar3 + 5) = 0xb2;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eedde98);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e7efac0;
      iVar9 = FUN_23a35f020(plVar12);
      lVar15 = *plVar12 + -1;
      if (iVar9 != -1) {
        *plVar12 = lVar15;
        if (lVar15 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (iVar9 != 1) goto LAB_23e7ef3d6;
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde70);
        if (plVar10 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0xb3;
          plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeddea0);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0xb4;
              plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeddea0);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
                if (plVar10 == (longlong *)0x0) {
LAB_23e7f0750:
                  pcVar18 = *(code **)(param_1 + 0x70);
                  plVar11 = *(longlong **)(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar17 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (pcVar18 == (code *)0x0) {
LAB_23e7f09c9:
                    uVar19 = 0xb5;
                    goto LAB_23e7effc0;
                  }
                  plVar10 = *(longlong **)(pcVar18 + 0x18);
                }
                else {
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeddea8);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar15 = _DAT_23eeddeb0;
                  if (plVar11 != (longlong *)0x0) {
                    *(undefined4 *)(plVar3 + 5) = 0xb5;
                    plVar10 = (longlong *)
                              FUN_23e9186b0(param_1,plVar11,lVar15 + 0x18,_DAT_23eeddeb8);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar10 != (longlong *)0x0) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      goto LAB_23e7ef3d6;
                    }
                    goto LAB_23e7f0750;
                  }
                  pcVar18 = *(code **)(param_1 + 0x70);
                  plVar11 = *(longlong **)(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar17 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (pcVar18 == (code *)0x0) goto LAB_23e7f09c9;
                  plVar10 = *(longlong **)(pcVar18 + 0x18);
                }
                uVar19 = 0xb5;
                goto joined_r0x00023e7f07cf;
              }
            }
            pcVar18 = *(code **)(param_1 + 0x70);
            plVar11 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar17 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar18 == (code *)0x0) {
              uVar19 = 0xb4;
              goto LAB_23e7effc0;
            }
            uVar19 = 0xb4;
            plVar10 = *(longlong **)(pcVar18 + 0x18);
            goto joined_r0x00023e7f07cf;
          }
        }
        pcVar18 = *(code **)(param_1 + 0x70);
        plVar11 = *(longlong **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar17 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar18 == (code *)0x0) {
          uVar19 = 0xb3;
          goto LAB_23e7effc0;
        }
        uVar19 = 0xb3;
        plVar10 = *(longlong **)(pcVar18 + 0x18);
        goto joined_r0x00023e7f07cf;
      }
      plVar11 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar12 = lVar15;
      if (lVar15 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (pcVar18 != (code *)0x0) {
        uVar19 = 0xb2;
        plVar10 = *(longlong **)(pcVar18 + 0x18);
        goto joined_r0x00023e7f07cf;
      }
LAB_23e7f0220:
      uVar19 = 0xb2;
LAB_23e7effc0:
      pcVar16 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar18 = _PyRuntime_exref;
      *(longlong *)(pcVar16 + 0x10) = 0;
      *(longlong **)(pcVar16 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar15 = *(longlong *)(pcVar18 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      lVar15 = *(longlong *)(lVar15 + 0x10);
      *(undefined4 *)(pcVar16 + 0x24) = uVar19;
      lVar15 = *(longlong *)(lVar15 + 0x2e8);
      lVar2 = *(longlong *)(pcVar16 + -8);
      puVar4 = *(undefined8 **)(lVar15 + 8);
      *puVar4 = pcVar16 + -0x10;
      *(longlong *)(pcVar16 + -0x10) = lVar15;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(code **)(lVar15 + 8) = pcVar16 + -0x10;
      goto LAB_23e7efb90;
    }
LAB_23e7ef3d6:
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde58);
    if (plVar10 != (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd90);
      if (plVar11 != (longlong *)0x0) {
        *(undefined4 *)(plVar3 + 5) = 0xb8;
        plVar12 = (longlong *)FUN_23e91a870(param_1,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e7efc40;
        plVar13 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd98);
        if (plVar13 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x60);
          pcVar17 = *(code **)(param_1 + 0x68);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            iStack_d0 = 0xb8;
LAB_23e7f0157:
            (**(code **)(plVar10[1] + 0x30))(plVar10);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
LAB_23e7f0172:
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar13 != (longlong *)0x0) goto LAB_23e7f018f;
LAB_23e7f02c0:
            if (pcVar18 != (code *)0x0) {
              pcVar16 = pcVar18;
              if (*(longlong **)(pcVar18 + 0x18) == plVar3) goto LAB_23e7efb90;
              if (iStack_d0 != 0) goto LAB_23e7efcf2;
              uVar19 = (undefined4)plVar3[5];
              goto LAB_23e7efaf5;
            }
            if (iStack_d0 != 0) goto LAB_23e7f0660;
            uVar19 = (undefined4)plVar3[5];
            goto LAB_23e7effc0;
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            iStack_d0 = 0xb8;
            goto LAB_23e7f02c0;
          }
          uVar19 = 0xb8;
          if (pcVar18 == (code *)0x0) goto LAB_23e7effc0;
          goto LAB_23e7efc86;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
        if (plVar11 == (longlong *)0x0) {
LAB_23e7efd00:
          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar14 = *(longlong **)(param_1 + 0x138);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (plVar14 != (longlong *)0x0) {
            *plVar14 = *plVar14 + 1;
          }
          pcVar17 = DAT_23ed6a4f8;
          apcStack_88[0] = pcVar18;
          if (pcVar18 == (code *)0x0) {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar18 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar18;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong *)(pcVar17 + 0x10) = 0;
            *(longlong **)(pcVar17 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            *(longlong *)(pcVar17 + 0x20) = 0xb9ffffffff;
            lVar15 = *(longlong *)
                      (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = *(longlong *)(pcVar17 + -8);
            puVar4 = *(undefined8 **)(lVar15 + 8);
            *puVar4 = pcVar17 + -0x10;
            *(longlong *)(pcVar17 + -0x10) = lVar15;
            *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(code **)(lVar15 + 8) = pcVar17 + -0x10;
            if ((apcStack_88[0] != (code *)0x0) &&
               (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
               *(longlong *)apcStack_88[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
            }
          }
          else {
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              pcVar16 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar16;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            *(longlong **)(pcVar17 + 0x18) = plVar3;
            *plVar3 = *plVar3 + 1;
            *(longlong *)(pcVar17 + 0x20) = 0xb9ffffffff;
            lVar15 = *(longlong *)
                      (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = *(longlong *)(pcVar17 + -8);
            puVar4 = *(undefined8 **)(lVar15 + 8);
            *puVar4 = pcVar17 + -0x10;
            *(longlong *)(pcVar17 + -0x10) = lVar15;
            *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(code **)(lVar15 + 8) = pcVar17 + -0x10;
            *(code **)(pcVar17 + 0x10) = pcVar18;
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            if ((apcStack_88[0] != (code *)0x0) &&
               (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
               *(longlong *)apcStack_88[0] == 0)) {
              (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
            }
          }
          pcVar18 = _Py_NoneStruct_exref;
          apcStack_88[0] = pcVar17;
          if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
             ((code *)auStack_98._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
          }
          plVar11 = *(longlong **)(auStack_98._8_8_ + 0x28);
          if (apcStack_88[0] == pcVar18) {
            pcVar17 = (code *)0x0;
          }
          else {
            pcVar17 = apcStack_88[0];
            if (apcStack_88[0] != (code *)0x0) {
              *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
            }
          }
          *(code **)(auStack_98._8_8_ + 0x28) = pcVar17;
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          plVar11 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
          if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
          if (*(longlong *)auStack_98._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_88[0] != (code *)0x0) &&
             (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
             *(longlong *)apcStack_88[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
          }
          apcStack_88[0] = (code *)0x0;
          auStack_98 = (undefined1  [16])0x0;
          iVar9 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                *(undefined8 *)PyExc_BaseException_exref);
          if (iVar9 == 0) {
            pcVar16 = *(code **)(param_1 + 0x138);
            if ((pcVar16 == pcVar18) || (pcVar16 == (code *)0x0)) {
              plVar11 = *(longlong **)PyExc_RuntimeError_exref;
              pcVar17 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar16 = *(code **)(param_1 + 0x138);
              *plVar11 = *plVar11 + 1;
              *(longlong **)(param_1 + 0x138) = plVar14;
              if (pcVar16 != (code *)0x0) {
                iStack_d0 = 0xb8;
                pcVar18 = (code *)0x0;
                bVar5 = true;
                goto LAB_23e7f03fd;
              }
              pcStack_a8 = (code *)0x0;
              iStack_d0 = 0xb8;
              plStack_b8 = plVar11;
              pcStack_b0 = pcVar17;
            }
            else {
              plVar11 = *(longlong **)(pcVar16 + 8);
              pcVar18 = *(code **)(pcVar16 + 0x28);
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
              *plVar11 = *plVar11 + 1;
              if ((pcVar18 != (code *)0x0) &&
                 (*(longlong *)pcVar18 = *(longlong *)pcVar18 + 1,
                 plVar3 == *(longlong **)(pcVar18 + 0x18))) {
                *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
              }
              bVar5 = true;
              *(longlong **)(param_1 + 0x138) = plVar14;
              iStack_d0 = 0;
              pcVar17 = pcVar16;
LAB_23e7f03fd:
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
              if (*(longlong *)pcVar16 == 0) {
                (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))();
              }
              plStack_b8 = plVar11;
              pcStack_b0 = pcVar17;
              pcStack_a8 = pcVar18;
              if (!bVar5) goto LAB_23e7f0437;
            }
            *(undefined4 *)(plVar3 + 5) = 0xb8;
            plVar14 = (longlong *)FUN_23e957a30(param_1,plVar13,DAT_23eedde28);
            if (plVar14 == (longlong *)0x0) {
              pcVar18 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              FUN_23a35d6b0(&plStack_b8);
              iStack_d0 = 0xb8;
            }
            else {
              *plVar14 = *plVar14 + -1;
              pcVar18 = pcStack_a8;
              pcVar17 = pcStack_b0;
              plVar11 = plStack_b8;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
                pcVar18 = pcStack_a8;
                pcVar17 = pcStack_b0;
                plVar11 = plStack_b8;
              }
            }
          }
          else {
            pcStack_70 = *(code **)(param_1 + 0x138);
            plStack_78 = *(longlong **)(pcStack_70 + 8);
            pcStack_68 = *(code **)(pcStack_70 + 0x28);
            *(undefined4 *)(plVar3 + 5) = 0xb8;
            if (pcStack_68 == (code *)0x0) {
              pcStack_68 = pcVar18;
            }
            plVar11 = (longlong *)FUN_23e956150(param_1);
            if (plVar11 == (longlong *)0x0) {
              pcVar18 = *(code **)(param_1 + 0x70);
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              iVar9 = FUN_23a35f020(plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (iVar9 != -1) {
                if (iVar9 != 0) {
                  plVar11 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  if (plVar11 != (longlong *)0x0) goto LAB_23e7ef501;
                  goto LAB_23e7ef50e;
                }
                pcVar16 = *(code **)(param_1 + 0x138);
                bVar5 = false;
                if ((pcVar16 == (code *)0x0) || (pcVar16 == pcVar18)) {
                  plVar11 = *(longlong **)PyExc_RuntimeError_exref;
                  pcVar17 = (code *)PyUnicode_FromString("No active exception to reraise");
                  pcVar16 = *(code **)(param_1 + 0x138);
                  *plVar11 = *plVar11 + 1;
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  if (pcVar16 == (code *)0x0) {
                    pcStack_a8 = (code *)0x0;
                    iStack_d0 = 0xb8;
                    pcVar18 = (code *)0x0;
                    plStack_b8 = plVar11;
                    pcStack_b0 = pcVar17;
                    goto LAB_23e7f0437;
                  }
                  iStack_d0 = 0xb8;
                  pcVar18 = (code *)0x0;
                }
                else {
                  plVar11 = *(longlong **)(pcVar16 + 8);
                  pcVar18 = *(code **)(pcVar16 + 0x28);
                  *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                  *plVar11 = *plVar11 + 1;
                  if ((pcVar18 != (code *)0x0) &&
                     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + 1,
                     plVar3 == *(longlong **)(pcVar18 + 0x18))) {
                    *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar18 + 0x24);
                  }
                  iStack_d0 = 0;
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  pcVar17 = pcVar16;
                }
                goto LAB_23e7f03fd;
              }
              plVar11 = *(longlong **)(param_1 + 0x60);
              pcVar17 = *(code **)(param_1 + 0x68);
              pcVar18 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            pcVar16 = *(code **)(param_1 + 0x138);
            bVar5 = false;
            *(undefined8 *)(param_1 + 0x70) = 0;
            iStack_d0 = 0xb8;
            *(longlong **)(param_1 + 0x138) = plVar14;
            plStack_b8 = plVar11;
            pcStack_b0 = pcVar17;
            pcStack_a8 = pcVar18;
            if (pcVar16 != (code *)0x0) goto LAB_23e7f03fd;
          }
LAB_23e7f0437:
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) goto LAB_23e7f0157;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) goto LAB_23e7f0172;
LAB_23e7f018f:
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          goto LAB_23e7f02c0;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23eeddec0);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar14 == (longlong *)0x0) goto LAB_23e7efd00;
        *(undefined4 *)(plVar3 + 5) = 0xb9;
        plVar11 = (longlong *)FUN_23e91a870(param_1,plVar14);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (plVar11 == (longlong *)0x0) goto LAB_23e7efd00;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *(undefined4 *)(plVar3 + 5) = 0xb8;
        plVar11 = (longlong *)FUN_23e957a30(param_1,plVar13,DAT_23eedde28);
        if (plVar11 == (longlong *)0x0) {
          plVar11 = *(longlong **)(param_1 + 0x60);
          iStack_d0 = 0xb8;
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar17 = *(code **)(param_1 + 0x68);
          goto LAB_23e7f0437;
        }
LAB_23e7ef501:
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))();
        }
LAB_23e7ef50e:
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde70);
        if (plVar10 == (longlong *)0x0) {
LAB_23e7f0368:
          pcVar18 = *(code **)(param_1 + 0x70);
          plVar11 = *(longlong **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar17 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcVar18 != (code *)0x0) {
            uVar19 = 0xbb;
            plVar10 = *(longlong **)(pcVar18 + 0x18);
            goto joined_r0x00023e7f07cf;
          }
LAB_23e7f0908:
          uVar19 = 0xbb;
        }
        else {
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeddec0);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 == (longlong *)0x0) {
            pcVar18 = *(code **)(param_1 + 0x70);
            plVar11 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar17 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar18 != (code *)0x0) {
              uVar19 = 0xbb;
              plVar10 = *(longlong **)(pcVar18 + 0x18);
              goto joined_r0x00023e7f07cf;
            }
            goto LAB_23e7f0908;
          }
          *(undefined4 *)(plVar3 + 5) = 0xbb;
          plVar10 = (longlong *)FUN_23e91a870(param_1,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar10 == (longlong *)0x0) goto LAB_23e7f0368;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde78);
          if (plVar10 == (longlong *)0x0) {
LAB_23e7f05c0:
            pcVar18 = *(code **)(param_1 + 0x70);
            plVar11 = *(longlong **)(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar17 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar18 != (code *)0x0) {
              uVar19 = 0xbc;
              plVar10 = *(longlong **)(pcVar18 + 0x18);
              goto joined_r0x00023e7f07cf;
            }
LAB_23e7f09b3:
            uVar19 = 0xbc;
          }
          else {
            plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeddec0);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar11 == (longlong *)0x0) {
              pcVar18 = *(code **)(param_1 + 0x70);
              plVar11 = *(longlong **)(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar17 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar18 != (code *)0x0) {
                uVar19 = 0xbc;
                plVar10 = *(longlong **)(pcVar18 + 0x18);
                goto joined_r0x00023e7f07cf;
              }
              goto LAB_23e7f09b3;
            }
            *(undefined4 *)(plVar3 + 5) = 0xbc;
            plVar10 = (longlong *)FUN_23e91a870(param_1,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar10 == (longlong *)0x0) goto LAB_23e7f05c0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
            if (plVar10 == (longlong *)0x0) {
LAB_23e7f0310:
              pcVar18 = *(code **)(param_1 + 0x70);
              plVar11 = *(longlong **)(param_1 + 0x60);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar17 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar18 != (code *)0x0) {
                uVar19 = 0xbd;
                plVar10 = *(longlong **)(pcVar18 + 0x18);
                goto joined_r0x00023e7f07cf;
              }
LAB_23e7f09d4:
              uVar19 = 0xbd;
            }
            else {
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeddec0);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 == (longlong *)0x0) {
                pcVar18 = *(code **)(param_1 + 0x70);
                plVar11 = *(longlong **)(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar17 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar18 != (code *)0x0) {
                  uVar19 = 0xbd;
                  plVar10 = *(longlong **)(pcVar18 + 0x18);
                  goto joined_r0x00023e7f07cf;
                }
                goto LAB_23e7f09d4;
              }
              *(undefined4 *)(plVar3 + 5) = 0xbd;
              plVar10 = (longlong *)FUN_23e91a870(param_1,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar10 == (longlong *)0x0) goto LAB_23e7f0310;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              cVar8 = FUN_23e8d9ac0(plVar1,_DAT_23eedde90,_Py_FalseStruct_exref);
              if (cVar8 == '\0') {
                pcVar18 = *(code **)(param_1 + 0x70);
                plVar11 = *(longlong **)(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar17 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar18 != (code *)0x0) {
                  uVar19 = 0xbe;
                  plVar10 = *(longlong **)(pcVar18 + 0x18);
                  goto joined_r0x00023e7f07cf;
                }
                uVar19 = 0xbe;
              }
              else {
                lVar15 = FUN_23e8dd520();
                if (lVar15 == 0) {
                  FUN_23e915740(param_1,&plStack_78,_DAT_23eedde48);
                  plVar11 = plStack_78;
                  pcVar17 = pcStack_70;
                  pcVar18 = pcStack_68;
                }
                else {
                  plVar10 = (longlong *)FUN_23e8bc2f0(lVar15,_DAT_23eeddec8);
                  if (plVar10 != (longlong *)0x0) {
                    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedded0);
                    pcVar17 = _Py_TrueStruct_exref;
                    pcVar18 = _DAT_23eedded8;
                    if (plVar11 == (longlong *)0x0) {
                      plVar11 = *(longlong **)(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x68);
                      pcVar18 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      goto joined_r0x00023e7f0af1;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xbf;
                    pcStack_70 = pcVar17;
                    pcStack_68 = pcVar18;
                    plStack_78 = plVar11;
                    plVar12 = (longlong *)FUN_23e9186b0(param_1,plVar10,&plStack_78,_DAT_23eeddee0);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar12 != (longlong *)0x0) {
                      cVar8 = FUN_23e8d9ac0(plVar1,_DAT_23eedde88,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      if (cVar8 != '\0') {
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
                        if (plVar10 != (longlong *)0x0) {
                          *(undefined4 *)(plVar3 + 5) = 0xc0;
                          plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,_DAT_23eeddee8);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar11 != (longlong *)0x0) {
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              (**(code **)(plVar11[1] + 0x30))(plVar11);
                            }
                            lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                            plVar10 = *(longlong **)(lVar15 + 0x28);
                            plVar3 = (longlong *)plVar10[2];
                            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                 *(undefined8 *)(lVar15 + 0x30);
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
                            pcVar18 = _Py_NoneStruct_exref;
                            plVar10[0xf] = 0;
                            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                            *plVar1 = *plVar1 + -1;
                            if (*plVar1 != 0) {
                              return pcVar18;
                            }
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                            return pcVar18;
                          }
                        }
                        pcVar18 = *(code **)(param_1 + 0x70);
                        plVar11 = *(longlong **)(param_1 + 0x60);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcVar17 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcVar18 != (code *)0x0) {
                          uVar19 = 0xc0;
                          plVar10 = *(longlong **)(pcVar18 + 0x18);
                          goto joined_r0x00023e7f07cf;
                        }
                        uVar19 = 0xc0;
                        goto LAB_23e7effc0;
                      }
                    }
                  }
                  pcVar18 = *(code **)(param_1 + 0x70);
                  plVar11 = *(longlong **)(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar17 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
joined_r0x00023e7f0af1:
                if (pcVar18 != (code *)0x0) {
                  uVar19 = 0xbf;
                  plVar10 = *(longlong **)(pcVar18 + 0x18);
                  goto joined_r0x00023e7f07cf;
                }
                uVar19 = 0xbf;
              }
            }
          }
        }
        goto LAB_23e7effc0;
      }
LAB_23e7efc40:
      plVar11 = *(longlong **)(param_1 + 0x60);
      pcVar17 = *(code **)(param_1 + 0x68);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (pcVar18 == (code *)0x0) goto LAB_23e7f0660;
LAB_23e7efc86:
      uVar19 = 0xb8;
      plVar10 = *(longlong **)(pcVar18 + 0x18);
      goto joined_r0x00023e7f07cf;
    }
    pcVar18 = *(code **)(param_1 + 0x70);
    plVar11 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar17 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar18 == (code *)0x0) {
LAB_23e7f0660:
      uVar19 = 0xb8;
      goto LAB_23e7effc0;
    }
    pcVar16 = pcVar18;
    if (plVar3 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23e7efb90;
LAB_23e7efcf2:
    uVar19 = 0xb8;
  }
LAB_23e7efaf5:
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar7 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar7;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar7 = _PyRuntime_exref;
  *(longlong **)(pcVar16 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar15 = *(longlong *)(pcVar7 + 0x1f8);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar16 + 0x24) = uVar19;
  lVar15 = *(longlong *)(*(longlong *)(lVar15 + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar16 + -8);
  puVar4 = *(undefined8 **)(lVar15 + 8);
  *puVar4 = pcVar16 + -0x10;
  *(longlong *)(pcVar16 + -0x10) = lVar15;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
  lVar2 = *(longlong *)pcVar18;
  *(code **)(lVar15 + 8) = pcVar16 + -0x10;
  *(code **)(pcVar16 + 0x10) = pcVar18;
  if (lVar2 == 0) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
LAB_23e7efb90:
  FUN_23e8bba40(plVar3,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eedead0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedead0 = (longlong *)0x0;
  }
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar15 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
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
  FUN_23a33aa70(param_1,plVar11,pcVar17,pcVar16);
  return (code *)0x0;
}
