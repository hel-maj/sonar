/* ===== 23e7996c0 workers.fishing.garbage_disposal:? ===== */
/* ghidra_name=FUN_23e7996c0 entry=23e7996c0 size=10749 */

code * FUN_23e7996c0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined1 auVar9 [16];
  char cVar10;
  int iVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  longlong *plVar22;
  longlong *plVar23;
  code *pcVar24;
  undefined8 *puVar25;
  code *pcVar26;
  undefined4 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  code *local_130;
  longlong *local_128;
  longlong *local_110;
  longlong *local_108;
  longlong *local_f8;
  longlong *local_f0;
  undefined1 local_a8 [16];
  longlong *local_98;
  code *local_88;
  longlong *plStack_80;
  longlong *local_78;
  
  plVar23 = DAT_23eedac20;
  plVar1 = (longlong *)*param_3;
  pcVar2 = (code *)param_3[1];
  local_98 = (longlong *)0x0;
  plVar3 = (longlong *)param_3[2];
  local_a8 = (undefined1  [16])0x0;
  plVar4 = (longlong *)param_3[3];
  if (DAT_23eedac20 == (longlong *)0x0) {
LAB_23e799751:
    DAT_23eedac20 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac18,DAT_23eedacf8,0x80);
  }
  else {
    lVar12 = *DAT_23eedac20;
    if (1 < lVar12) {
      *DAT_23eedac20 = lVar12 + -1;
      goto LAB_23e799751;
    }
    if (DAT_23eedac20[2] != 0) {
      *DAT_23eedac20 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar23[1] + 0x30))(plVar23);
      }
      goto LAB_23e799751;
    }
  }
  plVar8 = DAT_23eedac20;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar23 = DAT_23eedac20 + 9;
  lVar5 = *(longlong *)(lVar12 + 8);
  DAT_23eedac20[0xf] = lVar5;
  *(longlong **)(lVar12 + 8) = plVar23;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar8[0xe] != 0)))) {
    plVar23 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar23;
    if (plVar23 != (longlong *)0x0) {
      *plVar23 = *plVar23 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  *(undefined4 *)(plVar8 + 8) = 0;
  iVar11 = FUN_23a35f020(plVar4);
  plVar23 = DAT_23ed6ccf0;
  if (iVar11 == -1) {
    local_98 = *(longlong **)(param_1 + 0x70);
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    uVar27 = 0x123;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    if (iVar11 == 0) {
      *(longlong *)pcVar2 = *(longlong *)pcVar2 + 1;
      *plVar23 = *plVar23 + 2;
      local_128 = plVar23;
      local_130 = pcVar2;
LAB_23e79981e:
      lVar12 = FUN_23e8df960();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_a8,DAT_23eed81e0);
        plVar15 = (longlong *)0x0;
LAB_23e79ab2f:
        local_f8 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        pcVar24 = (code *)0x0;
        local_f0 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        uVar27 = 0x131;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        goto LAB_23e79a450;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eed8428);
      if (plVar13 == (longlong *)0x0) {
        local_98 = *(longlong **)(param_1 + 0x70);
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        plVar16 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        uVar27 = 0x131;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar24 = (code *)0x0;
        goto LAB_23e79a450;
      }
      lVar12 = FUN_23e8df960();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_a8,DAT_23eed81e0);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        plVar15 = (longlong *)0x0;
        goto LAB_23e79ab2f;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eed8430);
      if (plVar14 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        local_f8 = (longlong *)0x0;
        pcVar24 = (code *)0x0;
        plVar15 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        uVar27 = 0x131;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        goto LAB_23e79a450;
      }
      *(undefined4 *)(plVar8 + 5) = 0x131;
      local_88 = local_130;
      plStack_80 = plVar3;
      local_78 = plVar14;
      plVar15 = (longlong *)FUN_23e956150(param_1,plVar13,&local_88);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar15 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e79ab2f;
      }
      lVar12 = FUN_23e8df420();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_a8,DAT_23eed81a0);
        plVar13 = (longlong *)0x0;
LAB_23e79b577:
        local_f8 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        pcVar24 = (code *)0x0;
        plVar14 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        uVar27 = 0x134;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        goto LAB_23e79a450;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eed8458);
      if (plVar14 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98 = *(longlong **)(param_1 + 0x70);
        plVar16 = (longlong *)0x0;
        pcVar24 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        uVar27 = 0x134;
        local_f8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e79a450;
      }
      lVar12 = FUN_23e8df570();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,local_a8,DAT_23eed8440);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        plVar13 = (longlong *)0x0;
        goto LAB_23e79b577;
      }
      plVar16 = (longlong *)FUN_23e8d1240(plVar15,lVar12);
      if (plVar16 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        local_f8 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        uVar27 = 0x134;
        local_108 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        pcVar24 = (code *)0x0;
        goto LAB_23e79a450;
      }
      *(undefined4 *)(plVar8 + 5) = 0x134;
      plVar13 = (longlong *)FUN_23e914090(param_1,plVar14,plVar16);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plVar13 == (longlong *)0x0) {
        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_98 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e79b577;
      }
      lVar12 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar12 + 0x1188) == 0) {
        pcVar24 = (code *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar11 = *(int *)(lVar12 + 0x1188) + -1;
        *(int *)(lVar12 + 0x1188) = iVar11;
        pcVar24 = *(code **)(lVar12 + 0xf08 + (longlong)iVar11 * 8);
        *(longlong *)pcVar24 = 1;
      }
      pcVar26 = _PyRuntime_exref;
      *(longlong *)(pcVar24 + 0x10) = 0;
      *(longlong *)(pcVar24 + 0x20) = 0;
      lVar12 = *(longlong *)(pcVar26 + 0x1f8);
      *(longlong *)(pcVar24 + 0x18) = 0;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar5 = *(longlong *)(pcVar24 + -8);
      puVar25 = *(undefined8 **)(lVar12 + 8);
      *puVar25 = pcVar24 + -0x10;
      *(longlong *)(pcVar24 + -0x10) = lVar12;
      *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar25;
      *(code **)(lVar12 + 8) = pcVar24 + -0x10;
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar3,DAT_23eed81d8);
      if (plVar14 == (longlong *)0x0) {
LAB_23e79ab78:
        plVar18 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar28 = *(undefined8 *)(param_1 + 0x60);
        uVar29 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        plVar16 = (longlong *)FUN_23a38cc10(param_1,plVar14,DAT_23eed8448);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (plVar16 == (longlong *)0x0) goto LAB_23e79ab78;
        plVar17 = (longlong *)FUN_23a388310(plVar16);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (plVar17 == (longlong *)0x0) goto LAB_23e79ab78;
        plVar14 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
        if ((plVar14 == (longlong *)0x0) &&
           (plVar14 = (longlong *)FUN_23a3c1b70(param_1,local_a8,0,2), plVar14 == (longlong *)0x0))
        {
          local_110 = (longlong *)0x0;
        }
        else {
          local_110 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
          if (((local_110 != (longlong *)0x0) ||
              (local_110 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,2),
              local_110 != (longlong *)0x0)) &&
             (cVar10 = FUN_23a3884a0(param_1,local_a8,plVar17), cVar10 != '\0')) {
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (*local_110 == 0) {
              (**(code **)(local_110[1] + 0x30))();
            }
            local_108 = (longlong *)FUN_23a38cc10(param_1,plVar13);
            pcVar26 = PyZip_Type_exref;
            if (local_108 != (longlong *)0x0) {
              *(longlong *)PyZip_Type_exref = *(longlong *)PyZip_Type_exref + 1;
              local_88 = pcVar26;
              plStack_80 = local_108;
              local_108 = (longlong *)FUN_23ab01810(param_1);
              if (local_108 != (longlong *)0x0) {
                plVar17 = (longlong *)FUN_23ebf7180();
                lVar12 = *local_108;
                *local_108 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(local_108[1] + 0x30))();
                }
                if (plVar17 == (longlong *)0x0) {
                  local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_98 = *(longlong **)(param_1 + 0x70);
                  local_f8 = (longlong *)0x0;
                  plVar16 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar27 = 0x13a;
                  local_f0 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  plVar16 = (longlong *)0x0;
                  local_f0 = (longlong *)0x0;
                  local_f8 = (longlong *)0x0;
                  local_108 = (longlong *)0x0;
                  do {
                    if (*(code **)(plVar17[1] + 0xe0) == (code *)0x0) {
                      PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                   "\'%s\' object is not an iterator");
LAB_23e79b873:
                      cVar10 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                      if (cVar10 == '\0') {
                        plVar18 = *(longlong **)(param_1 + 0x70);
                        uVar28 = *(undefined8 *)(param_1 + 0x60);
                        uVar29 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_98 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        local_a8 = (undefined1  [16])0x0;
                        if (local_108 != (longlong *)0x0) {
                          uVar27 = 0x13a;
                          goto LAB_23e79b2a0;
                        }
                        uVar27 = 0x13a;
                        local_108 = (longlong *)0x0;
                        goto LAB_23e79b2e3;
                      }
                      if ((local_108 != (longlong *)0x0) &&
                         (*local_108 = *local_108 + -1, *local_108 == 0)) {
                        FUN_23a334bc0(local_108);
                      }
                      lVar12 = *plVar17;
                      *plVar17 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(plVar17);
                      }
                      iVar11 = FUN_23a35f020(pcVar24);
                      if (iVar11 == -1) {
                        local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_98 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar27 = 0x141;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e79a450;
                      }
                      pcVar26 = pcVar24;
                      if (iVar11 != 0) {
                        plVar17 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8488);
                        if (plVar17 == (longlong *)0x0) {
                          local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_98 = *(longlong **)(param_1 + 0x70);
                          uVar27 = 0x142;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e79a450;
                        }
                        *(undefined4 *)(plVar8 + 5) = 0x142;
                        plStack_80 = local_110;
                        local_88 = pcVar24;
                        local_78 = plVar14;
                        pcVar26 = (code *)FUN_23e956150(param_1,plVar17,&local_88);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0();
                        }
                        if (pcVar26 == (code *)0x0) {
                          local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_98 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar27 = 0x142;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e79a450;
                        }
                        *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
                        if (*(longlong *)pcVar24 == 0) {
                          FUN_23a334bc0(pcVar24);
                        }
                      }
                      lVar12 = *(longlong *)(param_1 + 0x38);
                      *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
                      lVar5 = *(longlong *)(lVar12 + 8);
                      plVar8 = *(longlong **)(lVar5 + 0x28);
                      plVar17 = (longlong *)plVar8[2];
                      *(undefined8 *)(lVar12 + 8) = *(undefined8 *)(lVar5 + 0x30);
                      *(undefined4 *)(plVar8 + 8) = 0xffffffff;
                      if (plVar17 != (longlong *)0x0) {
                        plVar8[2] = 0;
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          (**(code **)(plVar17[1] + 0x30))();
                        }
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      plVar8[0xf] = 0;
                      lVar12 = *(longlong *)local_130;
                      *(longlong *)local_130 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(local_130);
                      }
                      *plVar23 = *plVar23 + -1;
                      if (*plVar23 == 0) {
                        FUN_23a334bc0(plVar23);
                      }
                      lVar12 = *local_128;
                      *local_128 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(local_128);
                      }
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        FUN_23a334bc0(plVar13);
                      }
                      *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
                      if (*(longlong *)pcVar26 == 0) {
                        FUN_23a334bc0(pcVar26);
                      }
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        FUN_23a334bc0(plVar14);
                      }
                      lVar12 = *local_110;
                      *local_110 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(local_110);
                      }
                      if ((local_108 != (longlong *)0x0) &&
                         (*local_108 = *local_108 + -1, *local_108 == 0)) {
                        FUN_23a334bc0(local_108);
                      }
                      if ((plVar16 != (longlong *)0x0) &&
                         (lVar12 = *plVar16, *plVar16 = lVar12 + -1, lVar12 + -1 == 0)) {
                        FUN_23a334bc0(plVar16);
                      }
                      if ((local_f0 != (longlong *)0x0) &&
                         (lVar12 = *local_f0, *local_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
                        FUN_23a334bc0(local_f0);
                      }
                      if ((local_f8 != (longlong *)0x0) &&
                         (lVar12 = *local_f8, *local_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
                        FUN_23a334bc0(local_f8);
                      }
                      lVar12 = *plVar1;
                      *plVar1 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(plVar1);
                      }
                      lVar12 = *(longlong *)pcVar2;
                      *(longlong *)pcVar2 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(pcVar2);
                      }
                      lVar12 = *plVar3;
                      *plVar3 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        FUN_23a334bc0(plVar3);
                      }
                      lVar12 = *plVar4;
                      *plVar4 = lVar12 + -1;
                      if (lVar12 + -1 != 0) {
                        return pcVar26;
                      }
                      FUN_23a334bc0(plVar4);
                      return pcVar26;
                    }
                    plVar18 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                    if (plVar18 == (longlong *)0x0) goto LAB_23e79b873;
                    if (local_108 == (longlong *)0x0) {
                      *plVar18 = *plVar18 + 1;
                    }
                    else {
                      *local_108 = *local_108 + -1;
                      if (*local_108 == 0) {
                        (**(code **)(local_108[1] + 0x30))(local_108);
                        lVar12 = *plVar18;
                      }
                      else {
                        lVar12 = *plVar18;
                      }
                      *plVar18 = lVar12 + 1;
                      *local_108 = *local_108 + -1;
                      if (*local_108 == 0) {
                        (**(code **)(local_108[1] + 0x30))(local_108);
                      }
                    }
                    lVar12 = FUN_23a388650(param_1,plVar18,DAT_23ed6ccf8,1);
                    local_108 = plVar18;
                    if (lVar12 == 0) {
LAB_23e79bda3:
                      uVar28 = *(undefined8 *)(param_1 + 0x60);
                      plVar18 = *(longlong **)(param_1 + 0x70);
                      uVar27 = 0x13b;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar29 = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e79b2a0;
                    }
                    lVar5 = *(longlong *)(param_1 + 0x10);
                    plVar20 = *(longlong **)(lVar5 + 0xe20);
                    if (plVar20 == (longlong *)0x0) {
                      plVar20 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar6 = plVar20[3];
                      *(int *)(lVar5 + 0xebc) = *(int *)(lVar5 + 0xebc) + -1;
                      *(longlong *)(lVar5 + 0xe20) = lVar6;
                      *plVar20 = 1;
                    }
                    pcVar26 = _PyRuntime_exref;
                    plVar20[4] = 0;
                    lVar5 = *(longlong *)
                             (*(longlong *)(*(longlong *)(pcVar26 + 0x1f8) + 0x10) + 0x2e8);
                    lVar6 = plVar20[-1];
                    puVar25 = *(undefined8 **)(lVar5 + 8);
                    *puVar25 = plVar20 + -2;
                    plVar20[-2] = lVar5;
                    plVar20[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar25;
                    plVar19 = DAT_23ed6ccf0;
                    *(longlong **)(lVar5 + 8) = plVar20 + -2;
                    plVar20[3] = lVar12;
                    lVar12 = FUN_23a388650(param_1,plVar18,plVar19,0);
                    if (lVar12 == 0) {
                      local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      local_98 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        (**(code **)(plVar20[1] + 0x30))(plVar20);
                        uVar27 = 0x13b;
                        plVar18 = local_98;
                        uVar28 = local_a8._0_8_;
                        uVar29 = local_a8._8_8_;
                      }
                      else {
                        uVar27 = 0x13b;
                        plVar18 = local_98;
                        uVar28 = local_a8._0_8_;
                        uVar29 = local_a8._8_8_;
                      }
                      goto LAB_23e79b2a0;
                    }
                    plVar20[4] = lVar12;
                    plVar19 = (longlong *)FUN_23a38cc10(param_1,plVar15,plVar20);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      (**(code **)(plVar20[1] + 0x30))(plVar20);
                    }
                    if (plVar19 == (longlong *)0x0) goto LAB_23e79bda3;
                    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    plVar20 = (longlong *)FUN_23a388650(param_1,plVar18,DAT_23ed6ccf0,0);
                    plVar16 = plVar19;
                    if (plVar20 == (longlong *)0x0) goto LAB_23e79bc48;
                    if ((code *)local_110[1] == PyLong_Type_exref) {
                      plVar21 = (longlong *)
                                (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                                          (local_110,DAT_23eed8230);
                    }
                    else {
                      plVar21 = (longlong *)FUN_23e8c1be0(local_110);
                    }
                    if (plVar21 == (longlong *)0x0) {
                      local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      local_98 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar20 = *plVar20 + -1;
                      if (*plVar20 == 0) {
                        (**(code **)(plVar20[1] + 0x30))(plVar20);
                      }
                      uVar27 = 0x13c;
                      plVar18 = local_98;
                      uVar28 = local_a8._0_8_;
                      uVar29 = local_a8._8_8_;
                      goto LAB_23e79b2a0;
                    }
                    plVar22 = (longlong *)FUN_23e8c09e0(plVar20,plVar21);
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      (**(code **)(plVar20[1] + 0x30))(plVar20);
                    }
                    *plVar21 = *plVar21 + -1;
                    if (*plVar21 == 0) {
                      (**(code **)(plVar21[1] + 0x30))(plVar21);
                    }
                    if (plVar22 == (longlong *)0x0) {
LAB_23e79bc48:
                      uVar27 = 0x13c;
                      uVar28 = *(undefined8 *)(param_1 + 0x60);
                      plVar18 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar29 = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e79b2a0;
                    }
                    plVar20 = (longlong *)FUN_23e8c09e0(plVar22,plVar23);
                    *plVar22 = *plVar22 + -1;
                    if (*plVar22 == 0) {
                      (**(code **)(plVar22[1] + 0x30))(plVar22);
                    }
                    if (plVar20 == (longlong *)0x0) goto LAB_23e79bc48;
                    if ((local_f0 != (longlong *)0x0) &&
                       (*local_f0 = *local_f0 + -1, *local_f0 == 0)) {
                      (**(code **)(local_f0[1] + 0x30))(local_f0);
                    }
                    plVar18 = (longlong *)FUN_23a388650(param_1,plVar18,DAT_23ed6ccf8,1);
                    local_f0 = plVar20;
                    if (plVar18 == (longlong *)0x0) goto LAB_23e79bd20;
                    if ((code *)plVar14[1] == PyLong_Type_exref) {
                      plVar21 = (longlong *)
                                (**(code **)(*(longlong *)(PyLong_Type_exref + 0x60) + 0xe8))
                                          (plVar14,DAT_23eed8230);
                    }
                    else {
                      plVar21 = (longlong *)FUN_23e8c1be0(plVar14);
                    }
                    if (plVar21 == (longlong *)0x0) {
                      local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      local_98 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar18 = *plVar18 + -1;
                      if (*plVar18 == 0) {
                        (**(code **)(plVar18[1] + 0x30))(plVar18);
                      }
                      uVar27 = 0x13d;
                      plVar18 = local_98;
                      uVar28 = local_a8._0_8_;
                      uVar29 = local_a8._8_8_;
                      goto LAB_23e79b2a0;
                    }
                    plVar22 = (longlong *)FUN_23e8c09e0(plVar18,plVar21);
                    *plVar18 = *plVar18 + -1;
                    if (*plVar18 == 0) {
                      (**(code **)(plVar18[1] + 0x30))(plVar18);
                    }
                    *plVar21 = *plVar21 + -1;
                    if (*plVar21 == 0) {
                      (**(code **)(plVar21[1] + 0x30))(plVar21);
                    }
                    if (plVar22 == (longlong *)0x0) {
LAB_23e79bd20:
                      uVar28 = *(undefined8 *)(param_1 + 0x60);
                      plVar18 = *(longlong **)(param_1 + 0x70);
                      uVar27 = 0x13d;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar29 = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e79b2a0;
                    }
                    plVar18 = (longlong *)FUN_23e8c09e0(plVar22,local_128);
                    *plVar22 = *plVar22 + -1;
                    if (*plVar22 == 0) {
                      (**(code **)(plVar22[1] + 0x30))(plVar22);
                    }
                    if (plVar18 == (longlong *)0x0) goto LAB_23e79bd20;
                    if ((local_f8 != (longlong *)0x0) &&
                       (*local_f8 = *local_f8 + -1, *local_f8 == 0)) {
                      (**(code **)(local_f8[1] + 0x30))(local_f8);
                    }
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    puVar25 = *(undefined8 **)(lVar12 + 0xe28);
                    if (puVar25 == (undefined8 *)0x0) {
                      puVar25 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,3);
                    }
                    else {
                      uVar28 = puVar25[3];
                      *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                      *(undefined8 *)(lVar12 + 0xe28) = uVar28;
                      *puVar25 = 1;
                    }
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8
                              );
                    uVar28 = puVar25[-1];
                    puVar7 = *(undefined8 **)(lVar12 + 8);
                    *puVar7 = puVar25 + -2;
                    puVar25[-2] = lVar12;
                    puVar25[-1] = (ulonglong)((uint)uVar28 & 3) | (ulonglong)puVar7;
                    *(undefined8 **)(lVar12 + 8) = puVar25 + -2;
                    *plVar20 = *plVar20 + 1;
                    puVar25[3] = plVar20;
                    *plVar18 = *plVar18 + 1;
                    puVar25[4] = plVar18;
                    *plVar19 = *plVar19 + 1;
                    puVar25[5] = plVar19;
                    FUN_23e8ba4b0(pcVar24);
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    local_f8 = plVar18;
                    if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                         (*(int *)(lVar12 + 0x78) != 0)) &&
                        (iVar11 = Py_MakePendingCalls(), iVar11 < 0)) &&
                       (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e79b51a;
                    if (*(int *)(lVar12 + 0x68) == 0) {
                      plVar18 = *(longlong **)(param_1 + 0x90);
                    }
                    else {
                      PyEval_SaveThread();
                      PyEval_AcquireThread(param_1);
                      plVar18 = *(longlong **)(param_1 + 0x90);
                    }
                  } while (plVar18 == (longlong *)0x0);
                  plVar20 = *(longlong **)(param_1 + 0x60);
                  plVar19 = *(longlong **)(param_1 + 0x68);
                  plVar21 = *(longlong **)(param_1 + 0x70);
                  *(longlong **)(param_1 + 0x60) = plVar18;
                  *(undefined8 *)(param_1 + 0x90) = 0;
                  *plVar18 = *plVar18 + 1;
                  *(undefined8 *)(param_1 + 0x68) = 0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                    (**(code **)(plVar20[1] + 0x30))();
                  }
                  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                    (**(code **)(plVar19[1] + 0x30))(plVar19);
                  }
                  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                    (**(code **)(plVar21[1] + 0x30))(plVar21);
                  }
LAB_23e79b51a:
                  plVar18 = *(longlong **)(param_1 + 0x70);
                  uVar28 = *(undefined8 *)(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar27 = 0x13a;
                  uVar29 = *(undefined8 *)(param_1 + 0x68);
LAB_23e79b2a0:
                  local_98 = (longlong *)0x0;
                  local_a8 = (undefined1  [16])0x0;
                  lVar12 = *local_108;
                  *local_108 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(local_108[1] + 0x30))();
                  }
LAB_23e79b2e3:
                  lVar12 = *plVar17;
                  *plVar17 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar17[1] + 0x30))();
                  }
                  local_a8._8_8_ = uVar29;
                  local_a8._0_8_ = uVar28;
                  local_98 = plVar18;
                }
                goto LAB_23e79a450;
              }
            }
            local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_98 = *(longlong **)(param_1 + 0x70);
            local_f8 = (longlong *)0x0;
            plVar16 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar27 = 0x13a;
            local_f0 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e79a450;
          }
        }
        plVar18 = local_98;
        uVar28 = local_a8._0_8_;
        uVar29 = local_a8._8_8_;
        local_98 = (longlong *)0x0;
        local_a8 = (undefined1  [16])0x0;
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        local_98 = (longlong *)0x0;
        local_a8 = (undefined1  [16])0x0;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if ((local_110 != (longlong *)0x0) &&
           (lVar12 = *local_110, *local_110 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_110[1] + 0x30))();
        }
      }
      plVar16 = (longlong *)0x0;
      uVar27 = 0x137;
      plVar14 = (longlong *)0x0;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_a8._8_8_ = uVar29;
      local_a8._0_8_ = uVar28;
      local_98 = plVar18;
      goto LAB_23e79a450;
    }
    plVar23 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8410);
    if (plVar23 == (longlong *)0x0) {
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar24 = (code *)0x0;
      plVar13 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      uVar27 = 0x126;
      local_f8 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_130 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar23 = (longlong *)0x0;
      goto LAB_23e79a450;
    }
    plVar15 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8410);
    if (plVar15 == (longlong *)0x0) {
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar23 = *plVar23 + -1;
      local_130 = (code *)0x0;
      if (*plVar23 == 0) {
        (**(code **)(plVar23[1] + 0x30))(plVar23);
      }
LAB_23e79b142:
      local_f8 = (longlong *)0x0;
      pcVar24 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar23 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      uVar27 = 0x126;
      local_110 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e79a450;
    }
    plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8418);
    if (plVar13 == (longlong *)0x0) {
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar23 = *plVar23 + -1;
      if (*plVar23 == 0) {
        (**(code **)(plVar23[1] + 0x30))(plVar23);
      }
      lVar12 = *plVar15;
      *plVar15 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      local_f8 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      pcVar24 = (code *)0x0;
      plVar13 = (longlong *)0x0;
      plVar23 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      uVar27 = 0x126;
      local_110 = (longlong *)0x0;
      local_128 = (longlong *)0x0;
      local_130 = (code *)0x0;
      plVar15 = (longlong *)0x0;
      goto LAB_23e79a450;
    }
    plVar14 = (longlong *)FUN_23e8c09e0(plVar15,plVar13);
    lVar12 = *plVar15;
    *plVar15 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    pcVar24 = _Py_NoneStruct_exref;
    if (plVar14 == (longlong *)0x0) {
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar23 = *plVar23 + -1;
      if (*plVar23 == 0) {
        (**(code **)(plVar23[1] + 0x30))(plVar23);
      }
      local_f8 = (longlong *)0x0;
      pcVar24 = (code *)0x0;
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      local_f0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar23 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      uVar27 = 0x126;
      local_110 = (longlong *)0x0;
      local_130 = (code *)0x0;
      local_128 = (longlong *)0x0;
      goto LAB_23e79a450;
    }
    lVar12 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar23,plVar14,_Py_NoneStruct_exref);
    *plVar23 = *plVar23 + -1;
    if (*plVar23 == 0) {
      (**(code **)(plVar23[1] + 0x30))(plVar23);
    }
    lVar5 = *plVar14;
    *plVar14 = lVar5 + -1;
    if (lVar5 + -1 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    lVar5 = *(longlong *)(param_1 + 0x10);
    plVar23 = *(longlong **)(lVar5 + 0xe20);
    if (plVar23 == (longlong *)0x0) {
      plVar23 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar6 = plVar23[3];
      *(int *)(lVar5 + 0xebc) = *(int *)(lVar5 + 0xebc) + -1;
      *(longlong *)(lVar5 + 0xe20) = lVar6;
      *plVar23 = 1;
    }
    pcVar26 = _PyRuntime_exref;
    plVar23[4] = 0;
    lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar26 + 0x1f8) + 0x10) + 0x2e8);
    lVar6 = plVar23[-1];
    puVar25 = *(undefined8 **)(lVar5 + 8);
    *puVar25 = plVar23 + -2;
    uVar28 = DAT_23eed8338;
    plVar23[-2] = lVar5;
    plVar23[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar25;
    *(longlong **)(lVar5 + 8) = plVar23 + -2;
    plVar23[3] = lVar12;
    plVar15 = (longlong *)FUN_23a38cc10(param_1,plVar4,uVar28);
    if (plVar15 == (longlong *)0x0) {
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      plVar13 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8338);
      if (plVar13 != (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8420);
        if (plVar14 == (longlong *)0x0) {
          local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_98 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          goto LAB_23e79b051;
        }
        plVar16 = (longlong *)FUN_23e8c09e0(plVar13,plVar14);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (plVar16 != (longlong *)0x0) {
          lVar12 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar15,plVar16,pcVar24);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plVar23[4] = lVar12;
          local_130 = (code *)FUN_23a38cc10(param_1,pcVar2,plVar23);
          *plVar23 = *plVar23 + -1;
          if (*plVar23 == 0) {
            (**(code **)(plVar23[1] + 0x30))(plVar23);
          }
          if (local_130 != (code *)0x0) {
            plVar23 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8338);
            if (plVar23 == (longlong *)0x0) {
              local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_98 = *(longlong **)(param_1 + 0x70);
              plVar16 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar24 = (code *)0x0;
              plVar13 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              uVar27 = 0x129;
              local_f8 = (longlong *)0x0;
              local_f0 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              local_110 = (longlong *)0x0;
              local_128 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e79a450;
            }
            local_128 = (longlong *)FUN_23a38cc10(param_1,plVar4,DAT_23eed8410);
            if (local_128 == (longlong *)0x0) {
              local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_98 = *(longlong **)(param_1 + 0x70);
              plVar16 = (longlong *)0x0;
              plVar14 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar24 = (code *)0x0;
              plVar13 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              uVar27 = 0x12a;
              local_f8 = (longlong *)0x0;
              local_f0 = (longlong *)0x0;
              local_108 = (longlong *)0x0;
              local_110 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e79a450;
            }
            goto LAB_23e79981e;
          }
          local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_98 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e79b142;
        }
      }
      local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_98 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
    }
LAB_23e79b051:
    *plVar23 = *plVar23 + -1;
    if (*plVar23 == 0) {
      (**(code **)(plVar23[1] + 0x30))(plVar23);
    }
    uVar27 = 0x127;
  }
  local_f8 = (longlong *)0x0;
  pcVar24 = (code *)0x0;
  plVar16 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  local_f0 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  plVar23 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  local_110 = (longlong *)0x0;
  local_128 = (longlong *)0x0;
  local_130 = (code *)0x0;
LAB_23e79a450:
  plVar18 = local_98;
  plVar17 = DAT_23ed6a4f8;
  if (local_98 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar18 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar26 = _PyRuntime_exref;
    plVar17[2] = 0;
    plVar17[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar12 = *(longlong *)(pcVar26 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar27;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar5 = plVar17[-1];
    puVar25 = *(undefined8 **)(lVar12 + 8);
    *puVar25 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar25;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar18 = plVar17;
    if ((local_98 != (longlong *)0x0) && (*local_98 = *local_98 + -1, *local_98 == 0)) {
      (**(code **)(local_98[1] + 0x30))(local_98);
    }
  }
  else if ((longlong *)local_98[3] != plVar8) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar20 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar26 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar12 = *(longlong *)(pcVar26 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar27;
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar5 = plVar17[-1];
    puVar25 = *(undefined8 **)(lVar12 + 8);
    *puVar25 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar25;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar17[2] = (longlong)plVar18;
    *plVar18 = *plVar18 + 1;
    plVar18 = plVar17;
    if ((local_98 != (longlong *)0x0) && (*local_98 = *local_98 + -1, *local_98 == 0)) {
      (**(code **)(local_98[1] + 0x30))(local_98);
    }
  }
  local_98 = plVar18;
  FUN_23e8bba40(plVar8,"oooooooooooooooo",plVar1,pcVar2,plVar3,plVar4,local_130,plVar23,local_128,
                plVar15,plVar13,pcVar24,plVar14,local_110,local_108,plVar16,local_f0,local_f8);
  if (DAT_23eedac20 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    DAT_23eedac20 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar12 + 0x28);
  plVar17 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar17 = local_98;
  auVar9 = local_a8;
  plVar8[0xf] = 0;
  local_a8 = (undefined1  [16])0x0;
  local_98 = (longlong *)0x0;
  if ((local_130 != (code *)0x0) &&
     (lVar12 = *(longlong *)local_130, *(longlong *)local_130 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_130 + 8) + 0x30))(local_130);
  }
  if ((plVar23 != (longlong *)0x0) && (*plVar23 = *plVar23 + -1, *plVar23 == 0)) {
    (**(code **)(plVar23[1] + 0x30))(plVar23);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar12 = *local_128, *local_128 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))();
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((pcVar24 != (code *)0x0) &&
     (*(longlong *)pcVar24 = *(longlong *)pcVar24 + -1, *(longlong *)pcVar24 == 0)) {
    (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar12 = *local_110, *local_110 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar12 = *local_108, *local_108 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((local_f0 != (longlong *)0x0) &&
     (lVar12 = *local_f0, *local_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_f0[1] + 0x30))(local_f0);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar12 = *local_f8, *local_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  lVar12 = *plVar1;
  *plVar1 = lVar12 + -1;
  local_a8 = auVar9;
  local_98 = plVar17;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar12 = *(longlong *)pcVar2;
  *(longlong *)pcVar2 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(*(longlong *)(pcVar2 + 8) + 0x30))(pcVar2);
  }
  lVar12 = *plVar3;
  *plVar3 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar12 = *plVar4;
  *plVar4 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,local_a8._0_8_,local_a8._8_8_,local_98);
  return (code *)0x0;
}
