/* ===== 23e7f0b40 workers.fishing.memory_fish_read:194 ===== */
/* ghidra_name=FUN_23e7f0b40 entry=23e7f0b40 size=4819 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7f0b40(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  bool bVar6;
  undefined8 uVar7;
  code *pcVar8;
  code *pcVar9;
  char cVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  code *pcVar19;
  code *pcVar20;
  undefined4 uVar21;
  int local_b0;
  undefined1 local_98 [16];
  code *local_88 [2];
  longlong *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar12 = _DAT_23eedeac0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedeac0 == (longlong *)0x0) {
LAB_23e7f0b85:
    _DAT_23eedeac0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeab8,DAT_23eedebc0,8);
  }
  else {
    lVar2 = *_DAT_23eedeac0;
    if (1 < lVar2) {
      *_DAT_23eedeac0 = lVar2 + -1;
      goto LAB_23e7f0b85;
    }
    if (_DAT_23eedeac0[2] != 0) {
      *_DAT_23eedeac0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e7f0b85;
    }
  }
  plVar4 = _DAT_23eedeac0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eedeac0 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eedeac0[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar12;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar7 = _DAT_23eedde70;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
  if (plVar12 == (longlong *)0x0) {
    pcVar20 = *(code **)(param_1 + 0x70);
    plVar12 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar19 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar20 == (code *)0x0) {
LAB_23e7f1900:
      uVar21 = 0xc4;
      goto LAB_23e7f16c0;
    }
    uVar21 = 0xc4;
    plVar13 = *(longlong **)(pcVar20 + 0x18);
joined_r0x00023e7f0faf:
    pcVar17 = pcVar20;
    if (plVar13 == plVar4) goto LAB_23e7f1060;
  }
  else {
    *(undefined4 *)(plVar4 + 5) = 0xc4;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23eeddea0);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      pcVar20 = *(code **)(param_1 + 0x70);
      plVar12 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar19 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar20 == (code *)0x0) goto LAB_23e7f1900;
      uVar21 = 0xc4;
      plVar13 = *(longlong **)(pcVar20 + 0x18);
      goto joined_r0x00023e7f0faf;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
    if (plVar12 == (longlong *)0x0) {
      pcVar20 = *(code **)(param_1 + 0x70);
      plVar12 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar19 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar20 != (code *)0x0) {
        uVar21 = 0xc5;
        plVar13 = *(longlong **)(pcVar20 + 0x18);
        goto joined_r0x00023e7f0faf;
      }
LAB_23e7f18b0:
      uVar21 = 0xc5;
LAB_23e7f16c0:
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
      pcVar20 = _PyRuntime_exref;
      *(longlong *)(pcVar17 + 0x10) = 0;
      *(longlong **)(pcVar17 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar20 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar2 = *(longlong *)(lVar2 + 0x10);
      *(undefined4 *)(pcVar17 + 0x24) = uVar21;
      lVar2 = *(longlong *)(lVar2 + 0x2e8);
      lVar3 = *(longlong *)(pcVar17 + -8);
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar2;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      *(code **)(lVar2 + 8) = pcVar17 + -0x10;
      goto LAB_23e7f1060;
    }
    *(undefined4 *)(plVar4 + 5) = 0xc5;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23eeddea0);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      pcVar20 = *(code **)(param_1 + 0x70);
      plVar12 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar19 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar20 != (code *)0x0) {
        uVar21 = 0xc5;
        plVar13 = *(longlong **)(pcVar20 + 0x18);
        goto joined_r0x00023e7f0faf;
      }
      goto LAB_23e7f18b0;
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
    if (plVar13 == (longlong *)0x0) goto LAB_23e7f1130;
    iVar11 = FUN_23a35f020(plVar13);
    lVar2 = *plVar13 + -1;
    if (iVar11 == -1) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = lVar2;
      if (lVar2 != 0) {
        uVar21 = 199;
        if (pcVar20 != (code *)0x0) {
LAB_23e7f1a07:
          plVar13 = *(longlong **)(pcVar20 + 0x18);
          goto joined_r0x00023e7f0faf;
        }
        goto LAB_23e7f16c0;
      }
      (**(code **)(plVar13[1] + 0x30))(plVar13);
joined_r0x00023e7f16a0:
      if (pcVar20 != (code *)0x0) {
        uVar21 = 199;
LAB_23e7f115b:
        plVar13 = *(longlong **)(pcVar20 + 0x18);
        goto joined_r0x00023e7f0faf;
      }
      uVar21 = 199;
      goto LAB_23e7f16c0;
    }
    *plVar13 = lVar2;
    if (lVar2 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (iVar11 == 0) goto LAB_23e7f0d08;
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
    if (plVar12 == (longlong *)0x0) {
LAB_23e7f1130:
      pcVar20 = *(code **)(param_1 + 0x70);
      plVar12 = *(longlong **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar19 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto joined_r0x00023e7f16a0;
    }
    *(undefined4 *)(plVar4 + 5) = 199;
    plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23eedde98);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) goto LAB_23e7f1130;
    iVar11 = FUN_23a35f020(plVar13);
    lVar2 = *plVar13 + -1;
    if (iVar11 == -1) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = lVar2;
      if (lVar2 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        goto joined_r0x00023e7f16a0;
      }
      uVar21 = 199;
joined_r0x00023e7f1dd0:
      if (pcVar20 != (code *)0x0) goto LAB_23e7f115b;
      goto LAB_23e7f16c0;
    }
    *plVar13 = lVar2;
    if (lVar2 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if (iVar11 == 1) {
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde88);
      if (plVar12 == (longlong *)0x0) {
        pcVar20 = *(code **)(param_1 + 0x70);
        plVar12 = *(longlong **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar19 = *(code **)(param_1 + 0x68);
        uVar21 = 200;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar20 != (code *)0x0) goto LAB_23e7f1a07;
      }
      else {
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeddea8);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        lVar2 = _DAT_23eeddeb0;
        if (plVar13 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 200;
          plVar12 = (longlong *)FUN_23e9186b0(param_1,plVar13,lVar2 + 0x18,_DAT_23eeddeb8);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar12 != (longlong *)0x0) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            goto LAB_23e7f0d08;
          }
        }
        pcVar20 = *(code **)(param_1 + 0x70);
        plVar12 = *(longlong **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar19 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar20 != (code *)0x0) {
          uVar21 = 200;
          plVar13 = *(longlong **)(pcVar20 + 0x18);
          goto joined_r0x00023e7f0faf;
        }
      }
      uVar21 = 200;
      goto LAB_23e7f16c0;
    }
LAB_23e7f0d08:
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde58);
    if (plVar13 != (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd90);
      if (plVar12 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0xcb;
        plVar14 = (longlong *)FUN_23e91a870(param_1,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar14 != (longlong *)0x0) {
          plVar15 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd98);
          if (plVar15 == (longlong *)0x0) {
            plVar12 = *(longlong **)(param_1 + 0x60);
            pcVar19 = *(code **)(param_1 + 0x68);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              local_b0 = 0xcb;
              goto LAB_23e7f1b08;
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 != 0) {
              uVar21 = 0xcb;
              goto joined_r0x00023e7f1dd0;
            }
            (**(code **)(plVar14[1] + 0x30))(plVar14);
            local_b0 = 0xcb;
          }
          else {
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
            if (plVar12 == (longlong *)0x0) {
LAB_23e7f1288:
              local_98 = *(undefined1 (*) [16])(param_1 + 0x60);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar16 = *(longlong **)(param_1 + 0x138);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + 1;
              }
              pcVar19 = DAT_23ed6a4f8;
              local_88[0] = pcVar20;
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
                *(longlong **)(pcVar19 + 0x18) = plVar4;
                *plVar4 = *plVar4 + 1;
                *(longlong *)(pcVar19 + 0x20) = 0xccffffffff;
                lVar2 = *(longlong *)
                         (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                lVar3 = *(longlong *)(pcVar19 + -8);
                puVar5 = *(undefined8 **)(lVar2 + 8);
                *puVar5 = pcVar19 + -0x10;
                *(longlong *)(pcVar19 + -0x10) = lVar2;
                *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
                *(code **)(lVar2 + 8) = pcVar19 + -0x10;
                if ((local_88[0] != (code *)0x0) &&
                   (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                   *(longlong *)local_88[0] == 0)) {
                  (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
                }
              }
              else {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar17 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar17;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong **)(pcVar19 + 0x18) = plVar4;
                *plVar4 = *plVar4 + 1;
                *(longlong *)(pcVar19 + 0x20) = 0xccffffffff;
                lVar2 = *(longlong *)
                         (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                lVar3 = *(longlong *)(pcVar19 + -8);
                puVar5 = *(undefined8 **)(lVar2 + 8);
                *puVar5 = pcVar19 + -0x10;
                *(longlong *)(pcVar19 + -0x10) = lVar2;
                *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
                *(code **)(lVar2 + 8) = pcVar19 + -0x10;
                *(code **)(pcVar19 + 0x10) = pcVar20;
                *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                if ((local_88[0] != (code *)0x0) &&
                   (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                   *(longlong *)local_88[0] == 0)) {
                  (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
                }
              }
              pcVar20 = _Py_NoneStruct_exref;
              local_88[0] = pcVar19;
              if (((code *)local_98._0_8_ != _Py_NoneStruct_exref) &&
                 ((code *)local_98._0_8_ != (code *)0x0)) {
                FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
              }
              plVar12 = *(longlong **)(local_98._8_8_ + 0x28);
              if (local_88[0] == pcVar20) {
                pcVar19 = (code *)0x0;
              }
              else {
                pcVar19 = local_88[0];
                if (local_88[0] != (code *)0x0) {
                  *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
                }
              }
              *(code **)(local_98._8_8_ + 0x28) = pcVar19;
              if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                (**(code **)(plVar12[1] + 0x30))();
              }
              plVar12 = *(longlong **)(param_1 + 0x138);
              *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
              if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                (**(code **)(plVar12[1] + 0x30))();
              }
              *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
              if (*(longlong *)local_98._0_8_ == 0) {
                (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
              }
              if ((local_88[0] != (code *)0x0) &&
                 (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1,
                 *(longlong *)local_88[0] == 0)) {
                (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
              }
              local_88[0] = (code *)0x0;
              local_98 = (undefined1  [16])0x0;
              iVar11 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                     *(undefined8 *)PyExc_BaseException_exref);
              if (iVar11 == 0) {
                pcVar17 = *(code **)(param_1 + 0x138);
                if ((pcVar17 == pcVar20) || (pcVar17 == (code *)0x0)) {
                  plVar12 = *(longlong **)PyExc_RuntimeError_exref;
                  pcVar19 = (code *)PyUnicode_FromString("No active exception to reraise");
                  pcVar17 = *(code **)(param_1 + 0x138);
                  *plVar12 = *plVar12 + 1;
                  *(longlong **)(param_1 + 0x138) = plVar16;
                  if (pcVar17 != (code *)0x0) {
                    local_b0 = 0xcb;
                    pcVar20 = (code *)0x0;
                    bVar6 = true;
                    goto LAB_23e7f1a75;
                  }
                  local_68 = (code *)0x0;
                  local_b0 = 0xcb;
                  local_78 = plVar12;
                  pcStack_70 = pcVar19;
                }
                else {
                  plVar12 = *(longlong **)(pcVar17 + 8);
                  pcVar20 = *(code **)(pcVar17 + 0x28);
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                  *plVar12 = *plVar12 + 1;
                  if ((pcVar20 != (code *)0x0) &&
                     (*(longlong *)pcVar20 = *(longlong *)pcVar20 + 1,
                     plVar4 == *(longlong **)(pcVar20 + 0x18))) {
                    *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                  }
                  bVar6 = true;
                  *(longlong **)(param_1 + 0x138) = plVar16;
                  local_b0 = 0;
                  pcVar19 = pcVar17;
LAB_23e7f1a75:
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
                  if (*(longlong *)pcVar17 == 0) {
                    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
                  }
                  plVar16 = plVar12;
                  local_78 = plVar12;
                  pcVar8 = pcVar19;
                  pcStack_70 = pcVar19;
                  pcVar9 = pcVar20;
                  local_68 = pcVar20;
                  if (!bVar6) goto LAB_23e7f1aaf;
                }
                *(undefined4 *)(plVar4 + 5) = 0xcb;
                plVar18 = (longlong *)FUN_23e957a30(param_1,plVar15,DAT_23eedde28);
                if (plVar18 == (longlong *)0x0) {
                  pcVar20 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  FUN_23a35d6b0(&local_78);
                  local_b0 = 0xcb;
                  plVar16 = local_78;
                  pcVar8 = pcStack_70;
                  pcVar9 = local_68;
                }
                else {
                  *plVar18 = *plVar18 + -1;
                  pcVar20 = local_68;
                  plVar12 = local_78;
                  pcVar19 = pcStack_70;
                  plVar16 = local_78;
                  pcVar8 = pcStack_70;
                  pcVar9 = local_68;
                  if (*plVar18 == 0) {
                    (**(code **)(plVar18[1] + 0x30))(plVar18);
                    pcVar20 = local_68;
                    plVar12 = local_78;
                    pcVar19 = pcStack_70;
                    plVar16 = local_78;
                    pcVar8 = pcStack_70;
                    pcVar9 = local_68;
                  }
                }
              }
              else {
                pcStack_70 = *(code **)(param_1 + 0x138);
                local_78 = *(longlong **)(pcStack_70 + 8);
                local_68 = *(code **)(pcStack_70 + 0x28);
                *(undefined4 *)(plVar4 + 5) = 0xcb;
                if (local_68 == (code *)0x0) {
                  local_68 = pcVar20;
                }
                plVar12 = (longlong *)FUN_23e956150(param_1);
                if (plVar12 == (longlong *)0x0) {
                  pcVar20 = *(code **)(param_1 + 0x70);
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  iVar11 = FUN_23a35f020(plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (iVar11 != -1) {
                    if (iVar11 != 0) {
                      plVar12 = *(longlong **)(param_1 + 0x138);
                      *(longlong **)(param_1 + 0x138) = plVar16;
                      if (plVar12 != (longlong *)0x0) goto LAB_23e7f0e2a;
                      goto LAB_23e7f0e34;
                    }
                    pcVar17 = *(code **)(param_1 + 0x138);
                    bVar6 = false;
                    if ((pcVar17 == (code *)0x0) || (pcVar17 == pcVar20)) {
                      plVar12 = *(longlong **)PyExc_RuntimeError_exref;
                      pcVar19 = (code *)PyUnicode_FromString("No active exception to reraise");
                      pcVar17 = *(code **)(param_1 + 0x138);
                      *plVar12 = *plVar12 + 1;
                      *(longlong **)(param_1 + 0x138) = plVar16;
                      if (pcVar17 == (code *)0x0) {
                        local_68 = (code *)0x0;
                        local_b0 = 0xcb;
                        pcVar20 = (code *)0x0;
                        plVar16 = plVar12;
                        pcVar8 = pcVar19;
                        pcVar9 = local_68;
                        goto LAB_23e7f1aaf;
                      }
                      local_b0 = 0xcb;
                      pcVar20 = (code *)0x0;
                    }
                    else {
                      plVar12 = *(longlong **)(pcVar17 + 8);
                      pcVar20 = *(code **)(pcVar17 + 0x28);
                      *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                      *plVar12 = *plVar12 + 1;
                      pcVar19 = pcVar17;
                      if ((pcVar20 == (code *)0x0) ||
                         (*(longlong *)pcVar20 = *(longlong *)pcVar20 + 1,
                         plVar4 != *(longlong **)(pcVar20 + 0x18))) {
                        local_b0 = 0;
                        *(longlong **)(param_1 + 0x138) = plVar16;
                      }
                      else {
                        local_b0 = 0;
                        *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                        *(longlong **)(param_1 + 0x138) = plVar16;
                      }
                    }
                    goto LAB_23e7f1a75;
                  }
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x68);
                  pcVar20 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                pcVar17 = *(code **)(param_1 + 0x138);
                bVar6 = false;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_b0 = 0xcb;
                *(longlong **)(param_1 + 0x138) = plVar16;
                plVar16 = plVar12;
                pcVar8 = pcVar19;
                pcVar9 = pcVar20;
                if (pcVar17 != (code *)0x0) goto LAB_23e7f1a75;
              }
            }
            else {
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeddec0);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar16 == (longlong *)0x0) goto LAB_23e7f1288;
              *(undefined4 *)(plVar4 + 5) = 0xcc;
              plVar12 = (longlong *)FUN_23e91a870(param_1,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e7f1288;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *(undefined4 *)(plVar4 + 5) = 0xcb;
              plVar12 = (longlong *)FUN_23e957a30(param_1,plVar15,DAT_23eedde28);
              if (plVar12 != (longlong *)0x0) {
LAB_23e7f0e2a:
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
LAB_23e7f0e34:
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                cVar10 = FUN_23e8d9ac0(plVar1,_DAT_23eedde90,_Py_FalseStruct_exref);
                if (cVar10 != '\0') {
                  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar12 = *(longlong **)(lVar2 + 0x28);
                  plVar4 = (longlong *)plVar12[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30)
                  ;
                  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                  if (plVar4 != (longlong *)0x0) {
                    plVar12[2] = 0;
                    *plVar4 = *plVar4 + -1;
                    if (*plVar4 == 0) {
                      (**(code **)(plVar4[1] + 0x30))();
                    }
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  pcVar20 = _Py_NoneStruct_exref;
                  plVar12[0xf] = 0;
                  *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 != 0) {
                    return pcVar20;
                  }
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                  return pcVar20;
                }
                pcVar20 = *(code **)(param_1 + 0x70);
                plVar12 = *(longlong **)(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar19 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar20 != (code *)0x0) {
                  uVar21 = 0xce;
                  plVar13 = *(longlong **)(pcVar20 + 0x18);
                  goto joined_r0x00023e7f0faf;
                }
                uVar21 = 0xce;
                goto LAB_23e7f16c0;
              }
              plVar12 = *(longlong **)(param_1 + 0x60);
              local_b0 = 0xcb;
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar19 = *(code **)(param_1 + 0x68);
              plVar16 = local_78;
              pcVar8 = pcStack_70;
              pcVar9 = local_68;
            }
LAB_23e7f1aaf:
            local_68 = pcVar9;
            pcStack_70 = pcVar8;
            local_78 = plVar16;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
LAB_23e7f1b08:
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) goto LAB_23e7f1abc;
LAB_23e7f1ad0:
              if (plVar15 == (longlong *)0x0) goto LAB_23e7f1830;
            }
            else {
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
LAB_23e7f1abc:
                (**(code **)(plVar14[1] + 0x30))(plVar14);
                goto LAB_23e7f1ad0;
              }
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
          }
LAB_23e7f1830:
          if (pcVar20 == (code *)0x0) {
            if (local_b0 == 0) {
              uVar21 = (undefined4)plVar4[5];
              goto LAB_23e7f16c0;
            }
            goto LAB_23e7f18a0;
          }
          pcVar17 = pcVar20;
          if (*(longlong **)(pcVar20 + 0x18) == plVar4) goto LAB_23e7f1060;
          if (local_b0 != 0) goto LAB_23e7f1612;
          uVar21 = (undefined4)plVar4[5];
          goto LAB_23e7f0fc0;
        }
      }
      plVar12 = *(longlong **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x68);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (pcVar20 != (code *)0x0) {
        uVar21 = 0xcb;
        goto LAB_23e7f115b;
      }
LAB_23e7f18a0:
      uVar21 = 0xcb;
      goto LAB_23e7f16c0;
    }
    pcVar20 = *(code **)(param_1 + 0x70);
    plVar12 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar19 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar20 == (code *)0x0) goto LAB_23e7f18a0;
    pcVar17 = pcVar20;
    if (plVar4 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23e7f1060;
LAB_23e7f1612:
    uVar21 = 0xcb;
  }
LAB_23e7f0fc0:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar8 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar8;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar8 = _PyRuntime_exref;
  *(longlong **)(pcVar17 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  lVar2 = *(longlong *)(pcVar8 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar17 + 0x24) = uVar21;
  lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
  lVar3 = *(longlong *)(pcVar17 + -8);
  puVar5 = *(undefined8 **)(lVar2 + 8);
  *puVar5 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar2;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
  lVar3 = *(longlong *)pcVar20;
  *(code **)(lVar2 + 8) = pcVar17 + -0x10;
  *(code **)(pcVar17 + 0x10) = pcVar20;
  if (lVar3 == 0) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
LAB_23e7f1060:
  FUN_23e8bba40(plVar4,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eedeac0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedeac0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar2 + 0x28);
  plVar13 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,plVar12,pcVar19,pcVar17);
  return (code *)0x0;
}
